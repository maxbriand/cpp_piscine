/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:53:55 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/08 17:56:29 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN::calculator(std::string& calcul, size_t fpos)
{
	float	right_number;

	if (_digits.size() < 2)
		throw ErrorExpressionException();
	right_number = _digits.top();
	_digits.pop();
	if (calcul[fpos] == '+')
		_digits.top() = _digits.top() + right_number;
	if (calcul[fpos] == '-')
		_digits.top() = _digits.top() - right_number;
	if (calcul[fpos] == '*')
		_digits.top() = _digits.top() * right_number;
	if (calcul[fpos] == '/')
	{
		if (right_number == 0)
			throw DivisionByZeroException();
		_digits.top() = _digits.top() / right_number;
	}
}

void	RPN::parsing(std::string& calcul, size_t& fpos, size_t& lpos)
{
	fpos = calcul.find_first_not_of("1234567890+-*/ ");
	if (fpos != std::string::npos)
		throw ErrorExpressionException();
	fpos = calcul.find_first_not_of(" \t");
	if (fpos == std::string::npos)
		throw ErrorExpressionException();
	lpos = calcul.find_last_of("1234567890+-*/");
	if (!std::isdigit(calcul[fpos]))
		throw ErrorExpressionException();
	_digits.push(calcul[fpos] - '0');
}

float	RPN::calcul_processing(std::string calcul)
{
	size_t	fpos = 0;
	size_t	lpos = 0;

	parsing(calcul, fpos, lpos);
	fpos++;
	while (fpos <= lpos)
	{
		if (calcul[fpos] != ' ')
			throw ErrorExpressionException();
		fpos++;
		if (std::isdigit(calcul[fpos]))
			_digits.push(calcul[fpos] - '0');
		if (calcul[fpos] == '+' || calcul[fpos] == '-' || calcul[fpos] == '/' || calcul[fpos] == '*')
			calculator(calcul, fpos);
		fpos++;
	}
	if (_digits.size() != 1)
		throw ErrorExpressionException();
	return (_digits.top());
}

const char*	RPN::DivisionByZeroException::what() const throw()
{
	return ("Error: cannot divide by 0.");	
}

const char*	RPN::ErrorExpressionException::what() const throw()
{
	return ("Error: wrong expression.");	
}

RPN::RPN(){}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_digits = other._digits;
	return (*this);
}

RPN::~RPN(){}
