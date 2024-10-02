/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:12:25 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/02 17:00:31 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// have to finish this one
// void	is_first_line_valid(std::string line)
// {
// 	size_t i;

// 	i = 0;
// 	while (line.size() > i)
// 	{
// 		i += line.find_first_not_of(" \t");
		
		
// 	}
// 	if (std::strncmp(line.substr(i).c_str(), "date", 4))
// 		std::cerr << "Header is not like date | value";
// 	i += 4;
// 	i += line.substr(i).find_first_not_of(" \t");
// 	if (std::strncmp(line.substr(i).c_str(), "|", 1))
// 		std::cerr << "Header is not like date | value";
// 	i += 1;
// 	i += line.substr(i).find_first_not_of(" \t");
// 	if (std::strncmp(line.substr(i).c_str(), "|", 1))
// 		std::cerr << "Header is not like date | value";

// 	std::cout << i << std::endl;

// 	std::cout << line.substr(4) << std::endl;


// 	// if the first line doesnt respect the good format: write it

// }

void	BitcoinExchange::n_are_digits(std::string& line, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!isdigit(line[i]))
			throw InvalidDateException();
		i++;
	}
}

bool	is_leap_year(t_date &current_date)
{
		if (current_date.year % 4 == 0)
		{
			if (current_date.year % 100 == 0)
			{
				if (current_date.year % 400 == 0)
					return (true);
				else
					return (false);
			}
			else
			{
				return (true);
			}
		}
		return (false);
}

// // try too short line, like just 2 numbers / that could crash with REGEX
// // try tricky leap year and date like 29 or 28
void	BitcoinExchange::is_valid_date(std::string& line, t_date& current_date)
{
	int		cdm;
	std::string year;
	std::string month;
	std::string day;

	if (line.length() < 11 || line[4] != '-' || line[7] != '-')
		throw InvalidDateException();
	year = line.substr(0, 4);
	month = line.substr(5, 2);
	day = line.substr(8, 2);
	n_are_digits(year, 4);
	n_are_digits(month, 2);
	n_are_digits(day, 2);
	current_date.year = std::atoi(year.c_str());
	current_date.month = std::atoi(month.c_str());
	current_date.day = std::atoi(day.c_str());
	
	cdm = current_date.month;
	if (current_date.year < 2009 || (current_date.year == 2009 && current_date.month == 1 && current_date.day == 1))
		throw InvalidDateException();		
	if (cdm > 12 || cdm < 1)
		throw InvalidDateException();
	if ((cdm == 1 || cdm == 3 || cdm == 5 || cdm == 7 || cdm == 8 || cdm == 10 || cdm == 12) && (current_date.day < 1 || current_date.day > 31))
		throw InvalidDateException();
	if ((cdm == 4 || cdm == 6 || cdm == 9 || cdm == 11) && (current_date.day < 1 || current_date.day > 30))
		throw InvalidDateException();
	if (cdm == 2 && is_leap_year(current_date) && (current_date.day < 1 || current_date.day > 29))
		throw InvalidDateException();
	if (cdm == 2 && !is_leap_year(current_date) && (current_date.day < 1 || current_date.day > 28))
		throw InvalidDateException();
}

void	BitcoinExchange::print_bitcoin_portfolio_evolution(char* input_file)
{
	std::string	line;
	t_date		current_date;	
	size_t		pos;	

	std::ifstream	file(input_file);
	if (!file.is_open())
		throw InputFileException();
	getline(file, line);
	// is_first_line_valid(line);	// check that the first line is prototype like std::string / std::string
	// handle empty new line
	while (getline(file, line))
	{
		if (line == "")
			continue;
		try
		{
			pos = line.find_first_not_of(" \t");
			if (pos == std::string::npos)
				throw UncompleteLineException();				
			line = line.substr(pos);
			// continue cutting like that;

			is_valid_date(line, current_date);
			line = line.substr(10);
			line = line.substr(line.find_first_not_of(" \t"));
			if (line[0] == '|' && line.length() <= 1)
				throw SeparatorException();
			line = line.substr(1);
			line = line.substr(line.find_first_not_of(" \t"));
			std::cout << line << std::endl;
			// I HAVE TO PROTECT EVERYTIME I SKIP SPACE CHAR + I SUBSTR // what's the return of find_first is there is only space? -1?	

			// HAVE TO DELETE
			// std::cout << current_date.year << "-" << current_date.month << "-" << current_date.day << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << " => " << line << std::endl;
		}	
	}

	// Use a while loop to read each line
		/* 

			check the format of the value (between 0 and 1000)
			Looking for the best date for this line (the lower one)
			Convert number of bitcoin according to the date from input
		
			// if not, Print the result; (getline + result like: 2011-01-03 => 3 = 0.9)
			// if error: print error
		*/

}

BitcoinExchange::BitcoinExchange()
{
	std::string		line;
	t_date			current_date;
	int				value;

	std::ifstream	file("data.csv");
	if (!file.is_open())
		throw DataCsvNotFoundException();
	getline(file, line);
	std::stringstream	ss;
	while (getline(file, line))
	{
		ss << line.substr(0, 4);
		ss >> current_date.year;
		ss.clear(); ss.str("");
		ss << line.substr(5, 2);
		ss >> current_date.month;		
		ss.clear(); ss.str("");
		ss << line.substr(8, 2);
		ss >> current_date.day;
		ss.clear(); ss.str("");
		ss << line.substr(11);
		ss >> value;
		ss.clear(); ss.str("");
		_bitcoin_price_volatility[current_date] = value;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_bitcoin_price_volatility = other._bitcoin_price_volatility;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

// std::ostream&	operator<<(std::ostream& o, const t_date& date)
// {
// 	o << date.year << '-' << date.month << '-' << date.day;
// 	return(o);
// }
