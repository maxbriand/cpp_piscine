/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeExceptions.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:21:34 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/04 21:54:17 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char* BitcoinExchange::GetLineFailedException::what() const throw()
{
	return ("Error: GetLine function failed or empty file");
}

const char* BitcoinExchange::HeaderException::what() const throw()
{
	return ("Error: the first line header isn't like: \"date | value\"!");
}

const char* BitcoinExchange::DataCsvNotFoundException::what() const throw()
{
	return ("Error: data.csv not found in the current dir!");
}

const char* BitcoinExchange::InputFileException::what() const throw()
{
	return ("Error: input file opening issue!");
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Error: date not valid");
}

const char* BitcoinExchange::SeparatorException::what() const throw()
{
	return ("Error: separator missing or ended line");
}

const char* BitcoinExchange::UncompleteLineException::what() const throw()
{
	return ("Error: uncomplete line");
}

const char* BitcoinExchange::WrongValueException::what() const throw()
{
	return ("Error: wrong part value");
}
