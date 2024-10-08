/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/08 17:43:51 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::duplicate_numbers_check(std::deque<iint>& unsorted_chain)
{
	size_t 	nullpos = unsorted_chain.size();
	size_t	i = 0;
	size_t	j;

	while (i < nullpos)
	{
		j = i + 1;
		while (j < nullpos)
		{
			if (unsorted_chain[i] == unsorted_chain[j])
				throw WrongInputException();
			j++;
		}
		i++;
	}
}

void	PmergeMe::store_int_in_deque(std::deque <iint>& unsorted_chain, char** input)
{
	size_t		pos = 0;
	std::string	new_number;
	long		converted_number;

	while (*input != NULL)
	{
		new_number = *input;
		pos = new_number.find_first_not_of("+1234567890");
		if (pos != std::string::npos)
			throw WrongInputException();
		pos = new_number.find_last_of("+");
		if (pos != 0 && pos != std::string::npos)
			throw WrongInputException();
		converted_number = atol(new_number.c_str());
		if (converted_number > INT_MAX || converted_number < 0)
			throw WrongInputException();
		unsorted_chain.push_back(std::make_pair(static_cast<int> (converted_number), std::vector<int>()));
		input++;
	}
}

std::deque<iint>	PmergeMe::ford_johnson_sorting_algorithm(std::deque<iint>& unsorted_chain, int level)
{
	size_t				j = 0;
	size_t				i = 0;
	size_t				lenght;
	std::deque<iint>	loosers_chain;
	std::deque<iint>	winners_chain;
	std::deque<iint>	main_chain;
	const int			jacobsthal_numbers[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, \
									5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101};

	// Step 0: Catch the end of the recursivity
	lenght = unsorted_chain.size();
	if (lenght == 1)
		return (unsorted_chain);

	// Step 1: Pair off 2r of the players / leaving one man out if n is odd (in losers list)
	while (i + 1 < lenght)
	{
		if (unsorted_chain[i] < unsorted_chain[i + 1])
		{
			loosers_chain.push_back(unsorted_chain[i]);
			unsorted_chain[i + 1].second.push_back(j);
			winners_chain.push_back(unsorted_chain[i + 1]);
		}
		else
		{
			loosers_chain.push_back(unsorted_chain[i + 1]);
			unsorted_chain[i].second.push_back(j);
			winners_chain.push_back(unsorted_chain[i]);			
		}
		j++;
		i += 2;
	}
	if (lenght % 2)
		loosers_chain.push_back(unsorted_chain[i]);

// // Check looser list
// if (loosers_chain.size() > 1)
// 	std::cout << "looser list: " << loosers_chain[0].first << std::endl;
// else
// 	std::cout << "looser list: " << loosers_chain[0].first << std::endl;

// // Check winner list
// if (loosers_chain.size() > 1)
// 	std::cout << "winner list: " << winners_chain[1].first << std::endl;
// else
// 	std::cout << "winner list: " << winners_chain[0].first << std::endl;


	// Step 2: Send the winner list recursively
	main_chain = ford_johnson_sorting_algorithm(winners_chain, level + 1);

// check main chain
std::cout << main_chain[0].first << " AND " << main_chain[1].first <<std::endl;
	int b = main_chain[0].second.back();
	std::cout << "the index is: " << b << std::endl;
	main_chain.push_back(loosers_chain[b]);
	// std::cout << main_chain[0] << std::endl;

	// Step 3: Sort loosers according Jacobstahl sequence	
	



	(void) jacobsthal_numbers; // ok
	return (main_chain);
}

void	PmergeMe::merge_insert_sort(char ** input)
{
	std::deque <iint>	unsorted_chain;
	std::deque <iint>	sorted_chain;

	// Step 1: Create the positive int sequence
	store_int_in_deque(unsorted_chain, input);
	// Step 2: Check if duplicate numbers
	duplicate_numbers_check(unsorted_chain);
	// Step 3: Limit chain size
	if (unsorted_chain.size() > 1000000)
		throw WrongInputException(); 
	// Step 4: Sort positive integers using Ford Johnson algorithm
	sorted_chain = ford_johnson_sorting_algorithm(unsorted_chain, 0);
	// Step 5: Print elements

}

const char*	PmergeMe::WrongInputException::what() const throw()
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
