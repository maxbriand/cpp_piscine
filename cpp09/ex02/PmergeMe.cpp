/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/05 17:22:28 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// others functions

// accept +
void	PmergeMe::merge_insert_sort(std::string input)
{
	size_t	spos;

	spos = input.find_first_not_of(" 1234567890+");
	if (spos != std::string::npos)
		throw WrongInputException();
	spos = input.find_first_not_of(" \t");
	if (spos == std::string::npos)
		throw WrongInputException();
	

}

const char*	RPN::WrongInputException::what() const throw()
{
	return ("Error: wrong input");	
}

PmergeMe::PmergeMe()
	//: //init list
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
	//: //init list
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		// add variables to assignate
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{ // alloc variables?
}
