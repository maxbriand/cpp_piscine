/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:20:33 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 16:29:53 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (&other != this)
		return (*this);	
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

void	ScalarConverter::convert(const char* str)
{
	double n = std::atof(str);
	if (n >= 0 && n <= CHAR_MAX && std::isprint(n))
		std::cout << "char: " << GRN << static_cast<char>(n) << CLR << std::endl;
	else if (n >= 0 && n <= CHAR_MAX)
		std::cout << "char: " << PRP << "Non displayable" << CLR << std::endl;
	else
		std::cout << "char: " << RED << "Impossible" << CLR << std::endl;
	if (n <= INT_MAX && n >= INT_MIN)
		std::cout << "int: " << GRN << static_cast<int>(n) << CLR << std::endl;
	else
		std::cout << "int: " << RED << "Impossible" << CLR << std::endl;
	std::cout << "float: " << GRN << std::fixed << std::setprecision(1) << static_cast<float>(n) << CLR << std::endl;
	std::cout << "double: " << GRN << n << CLR << std::endl;
}


