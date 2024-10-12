/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/12 17:21:41 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t	PmergeMe::update_looser_pos(size_t pos, size_t looser_chain_size, size_t& jacobsthal_index)
{
	const size_t jacobsthal_sequence[] = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, \
										5460, 10922, 21844, 43690, 87380, 174762, 349524, 699050, 1398100};

	if (pos == 0 || pos - 1 == jacobsthal_sequence[jacobsthal_index - 1])
	{
		jacobsthal_index++;
		if (jacobsthal_sequence[jacobsthal_index] > looser_chain_size)
			pos = looser_chain_size;
		else
			pos = jacobsthal_sequence[jacobsthal_index];
	}
	else
	{
		pos --;
	}
	return (pos);
}

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
