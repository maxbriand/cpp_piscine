/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/10 16:09:09 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char*	PmergeMe::WrongInputException::what() const throw()
{
	return ("Error: wrong input");	
}

PmergeMe::PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void) other;
	return *this;
};

PmergeMe::~PmergeMe(){};
