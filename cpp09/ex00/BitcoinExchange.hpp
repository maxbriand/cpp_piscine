/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:08:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/04 21:40:17 by mbriand          ###   ########.fr       */
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

class BitcoinExchange 
{
   public:
		void	print_bitcoin_portfolio_evolution(char* input_file);
		class DataCsvNotFoundException : public std::exception {const char* what() const throw();};
		class InputFileException : public std::exception {const char* what() const throw();};
		class InvalidDateException : public std::exception {const char* what() const throw();};
		class SeparatorException : public std::exception {const char* what() const throw();};
		class UncompleteLineException : public std::exception {const char* what() const throw();};
		class WrongValueException : public std::exception {const char* what() const throw();};
		class HeaderException : public std::exception {const char* what() const throw();};
		class GetLineFailedException : public std::exception {const char* what() const throw();};

   private:
		std::map<t_date, float>	_bitcoin_price_volatility;
		int		is_valid_date(std::string& line, t_date& current_date);
		void	n_are_digits(std::string& line, int n);
		void	iterate_line(std::string line, t_date& current_date, float& current_value);
		int		has_good_separator(std::string& cut_line);
		int		is_valid_value(std::string& line, float& current_value);
		bool	good_end_line(size_t& pos);
		void	is_valid_first_line(std::string line);

   public:
	   BitcoinExchange();
	   BitcoinExchange(const BitcoinExchange& other);
	   BitcoinExchange& operator=(const BitcoinExchange& other);
	   ~BitcoinExchange();
};

#endif
