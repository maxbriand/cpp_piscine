/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:08:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/02 16:59:38 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <cstdlib>
# include <sstream>
# include <cstring>

typedef struct s_date
{
	int	year;
	int	month;
	int day;

	bool operator<(const s_date& other) const 
	{
        if (year != other.year) 
			return year < other.year;
        if (month != other.month) 
			return month < other.month;
        return day < other.day;
    }
} t_date;

std::ostream&	operator<<(std::ostream& o, const t_date& date);

class BitcoinExchange 
{
   public:
		void	print_bitcoin_portfolio_evolution(char* input_file);
		class DataCsvNotFoundException : public std::exception {
			const char* what() const throw(){return ("Error: data.csv not found in the current dir!");}};
		class InputFileException : public std::exception {
			const char* what() const throw(){return ("Error: input file opening issue!");}};
		class InvalidDateException : public std::exception {
			const char* what() const throw(){return ("Error: date not valid");}};
		class SeparatorException : public std::exception {
			const char* what() const throw(){return ("Error: separator missing or ended line");}};
		class UncompleteLineException : public std::exception {
			const char* what() const throw(){return ("Error: uncomplete line");}};

		// class TooLargeNumber : public std::exception {
		// 	const char* what() const throw(){return ("Error: Invalid Date Format")}};
		// Too low number
		// Bad input: not format date | value
		// first line error

   private:
		std::map<t_date, float>	_bitcoin_price_volatility;
		void	is_valid_date(std::string& line, t_date& current_date);
		void	n_are_digits(std::string& line, int n);

   public:
	   BitcoinExchange();
	   BitcoinExchange(const BitcoinExchange& other);
	   BitcoinExchange& operator=(const BitcoinExchange& other);
	   ~BitcoinExchange();
};

#endif
