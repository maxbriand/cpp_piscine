/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:22:14 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/27 14:31:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N){}

void	Span::addNumbers(int *begin, int* end)
{
	unsigned int	size;

	size = std::distance(begin, end);
	if (size == 0)
		return ;
	if (_int_vector.size() + size > _N)
		throw std::exception();
	_int_vector.insert(_int_vector.end(), begin, end);
}

void    Span::addNumber(int i)
{
	if (_int_vector.size() == _N)
		throw std::exception();
	_int_vector.push_back(i);
}

int	Span::shortestSpan()
{
	unsigned long	i;
	int				shortest_span;

	if (_int_vector.size() < 2)
		throw std::exception();
	std::sort(_int_vector.begin(), _int_vector.end());
	i = 2;
	shortest_span = _int_vector[1] - _int_vector[0];
	while (i < _int_vector.size())
	{
		if (shortest_span > _int_vector[i] - _int_vector[i - 1])
			shortest_span = _int_vector[i] - _int_vector[i - 1];
		i++;
	}
	return (shortest_span);
}

int	Span::longestSpan()
{
	if (_int_vector.size() < 2)
		throw std::exception();
	std::sort(_int_vector.begin(), _int_vector.end());
	return (_int_vector[_int_vector.size() - 1] - _int_vector[0]);
}

Span::Span(void)
	: _N(0)
{}

Span::~Span(){}

Span::Span(const Span& src)
{
	*this = src;	
}

Span&	Span::operator=(const Span& src)
{
	if (&src == this)
		return (*this);
	_N = src._N;
	_int_vector = src._int_vector;
	return (*this);
}
