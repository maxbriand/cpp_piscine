/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:12:25 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/04 21:54:21 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BitcoinExchange::is_valid_first_line(std::string line)
{
	int		i;
	size_t	pos;

	i = 0;	
	while (i < 4)
	{
		pos = line.find_first_not_of("\t ");
		if (i == 3 && pos == std::string::npos)
			break ;
		if (pos == std::string::npos)
			throw HeaderException();
		line = line.substr(pos);
		if (i == 0)
		{
			if (strncmp(line.c_str(), "date", 4))
				throw HeaderException();
			pos = 4;
		}
		if (i == 1)
		{
			if (line[0] != '|')
				throw HeaderException();
			pos = 1;
		}
		if (i == 2)
		{
			if (strncmp(line.c_str(), "value", 5))
				throw HeaderException();
			pos = 5;
		}
		if (line.size() > pos)
			line = line.substr(pos);
		else if (i == 2)
			break ;
		i++;
	}
}

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

int	BitcoinExchange::is_valid_date(std::string& line, t_date& current_date)
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
	return (10);
}

int	BitcoinExchange::has_good_separator(std::string& cut_line)
{
	if (cut_line[0] != '|' || cut_line.length() <= 1)
		throw SeparatorException();
	return (1);
}

int	handle_zero(std::string& line, float& current_value)
{
	int	i = 2;
	
	if (!strncmp(line.c_str(), "-0", 2) && (line[2] == '\0' || line[2] == ' ' || line[2] == '\t'))
	{
		current_value = 0;
		return (2);
	}
	if ((strncmp(line.c_str(), "0.", 2) && strncmp(line.c_str(), "-0.", 3)) || std::atof(line.c_str()) != 0)
		return (0);
	while (line[i] == '0')
		i++;
	current_value = 0;
	return(i);
}

int	BitcoinExchange::is_valid_value(std::string& line, float& current_value)
{
	int					pos;
	std::ostringstream	oss;

	pos = handle_zero(line, current_value);
	if (pos > 0)
		return (pos);
	if (line.length() == 1 && !std::isdigit(line[0]))
		throw WrongValueException();
	if (line.length() > 1 && (line[0] == '+' && !std::isdigit(line[1])))
		throw WrongValueException();
	if (line.length() > 1 && (line[0] != '+' && !std::isdigit(line[0])))
		throw WrongValueException();
	current_value = std::atof(line.c_str());
    if (current_value < 0 || current_value > 1000)
		throw WrongValueException();
	oss << current_value;
    std::string number_str = oss.str();
	pos = number_str.length();
	if (line[0] == '+')
		pos++;
	return (pos);
}

bool	BitcoinExchange::good_end_line(size_t& pos)
{
	if (pos != std::string::npos)
		throw WrongValueException();
	return (1);
}

void	BitcoinExchange::iterate_line(std::string line, t_date& current_date, float& current_value)
{
	int		i = 0;
	size_t	pos = 0;

	while (i < 4)
	{
		pos = line.find_first_not_of(" \t");
		if (i == 3 && good_end_line(pos))
			break;
		if (pos == std::string::npos)
			throw UncompleteLineException();
		line = line.substr(pos);
		if (i == 0)
			pos = is_valid_date(line, current_date);
		if (i == 1)
			pos = has_good_separator(line);
		if (i == 2)
			pos = is_valid_value(line, current_value);
		if (i == 2 && line[pos] == '\0')
			break;
		if (i < 2 && line[pos] == '\0')
			throw UncompleteLineException();
		line = line.substr(pos);
		i++;
	}
}

float	get_exchange_rate(t_date& current_date, std::map<t_date, float> bpv)
{
	std::map<t_date, float>::iterator it = bpv.begin();
	std::map<t_date, float>::iterator last = it;
	
	while (it != bpv.end())
	{
		if (current_date.year < it->first.year \
			|| (current_date.year == it->first.year && current_date.month < it->first.month) \
			|| (current_date.year == it->first.year && current_date.month == it->first.month \
			&& current_date.day < it->first.day))
			break;
		last = it;
		it++;
	}
	return(last->second);
}

void	BitcoinExchange::print_bitcoin_portfolio_evolution(char* input_file)
{
	std::string	line;
	t_date		current_date;
	float		current_value;
	float		exchange_rate;

	std::ifstream	file(input_file);
	if (!file.is_open())
		throw InputFileException();
	if (!getline(file, line))
	{
		if (file.fail())
		{
			file.close();
			throw GetLineFailedException();
		}
		return ;
	}
	try
	{
		is_valid_first_line(line);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	while (getline(file, line))
	{
		if (line == "")
			continue;
		try
		{
			iterate_line(line, current_date, current_value);
			exchange_rate = get_exchange_rate(current_date, _bitcoin_price_volatility);
			std::cout << line.substr(line.find_first_not_of("\t "), 10) << " => " << current_value << " = " \
				<< (current_value * exchange_rate) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << " => " << line << std::endl;
		}	
	}		
	if (file.fail() && !file.eof())
	{
		file.close();
		throw GetLineFailedException();
	}
	file.close();
}

BitcoinExchange::BitcoinExchange()
{
	std::string		line;
	t_date			current_date;
	float			value;

	std::ifstream	file("data.csv");
	if (!file.is_open())
		throw DataCsvNotFoundException();
	getline(file, line);
	if (file.fail())
	{
		file.close();
		throw GetLineFailedException();
	}
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
	if (file.fail() && !file.eof())
	{
		file.close();
		throw GetLineFailedException();
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
