/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/12 01:49:13 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <climits>
# include <cstdlib>
# include <ctime>
# include <cmath>
// can delete that
#include <unistd.h>
#include "colors.hpp"

typedef	std::pair<int, std::vector<int> >iint;

class PmergeMe 
{
   public:
		template <typename Container>
		Container	ford_johnson_sorting_algorithm(Container unsorted_chain, int level);
		class WrongInputException : public std::exception {const char* what() const throw();};
		template <typename Container>
		void	store_chain_in_container(Container& unsorted_chain, char** input);

   private:
		template <typename Container>
		void	duplicate_numbers_check(Container& unsorted_chain);

   public:
	   PmergeMe();
	   PmergeMe(const PmergeMe& other);
	   PmergeMe& operator=(const PmergeMe& other);
	   ~PmergeMe();
};

template <typename Container>
void		PmergeMe::duplicate_numbers_check(Container& unsorted_chain)
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

template <typename Container>
void	PmergeMe::store_chain_in_container(Container& unsorted_chain, char** input)
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
	if (unsorted_chain.size() > 15000)
		throw WrongInputException();
	duplicate_numbers_check(unsorted_chain);
}

template <typename Container>
Container	PmergeMe::ford_johnson_sorting_algorithm(Container unsorted_chain, int level)
{
	size_t				j = 0;
	size_t				i = 0;
	size_t				lenght;
	Container			loosers_chain;
	Container			winners_chain;
	Container			main_chain;

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

	// Step 2: Send the winner list recursively
	main_chain = ford_johnson_sorting_algorithm(winners_chain, level + 1);

	// Step 3: Sort loosers according Jacobstahl sequence	
	size_t 		j_index = 0; // the next index I will take
	// size_t 	 	winner_index_in_main_chain = 0; // to select the mirror number
	size_t		pos = 0;
	const size_t jacobsthal_sequence[] = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, \
			21844, 43690, 87380, 174762, 349524, 699050, 1398100};
	size_t		mid = 0;
	size_t		left = 0;
	size_t		right = 0;
	iint		looser_to_insert;
	size_t		range = 0;
	bool		odd = 0;
	Container	initial_main_chain = main_chain;
	Container	sorted_looser_chain;

	typename Container::iterator it = main_chain.begin(); 
	while (it != main_chain.end())
	{
		sorted_looser_chain.push_back(loosers_chain[it->second[level]]);
		it++;
	}
	if (main_chain.size() != loosers_chain.size())
		sorted_looser_chain.push_back(loosers_chain.back());



	// to delete 
	int	its_the_print = 0;

	while (main_chain.size() < unsorted_chain.size())
	{
		if (its_the_print == 0)
{
	std::cout << BLU << std::endl << "New loop: " << CLR << std::endl;
	std::cout << "Unsorted elements: ";
	for (typename Container::iterator it = unsorted_chain.begin(); it != unsorted_chain.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
	std::cout << "Initial main chain: ";
	for (typename Container::iterator it = initial_main_chain.begin(); it != initial_main_chain.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
	std::cout << "Sorted Looser Chain: ";
	for (typename Container::iterator it = sorted_looser_chain.begin(); it != sorted_looser_chain.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
	std::cout << YLW"Main chain" << ": ";
	for (typename Container::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl<<CLR;				
}
		
		// Get the looser_index in looser chain
		if (odd != 1 && winner_index_in_main_chain >= main_chain.size() - 1 \
			&& unsorted_chain.size() % 2 != 0 && winner_index_in_main_chain < jacobsthal_sequence[j_index])
		{
			looser_index = loosers_chain.size() - 1;
			odd = 1;
		}
		else
			looser_index = main_chain[winner_index_in_main_chain].second[level];
		// Select the looser element to insert
		looser_to_insert = loosers_chain[looser_index];
			std::cout << "Looser to insert: " << looser_to_insert.first << std::endl;;
		// Prepare binary searching: right is everytime bigger and left is everytime smaller
	
		right = winner_index_in_main_chain; 
		left = 0;
		
		// FOR ODD
		if (odd == 1 && looser_index == loosers_chain.size() - 1)
			right = main_chain.size();
		
		while (1)
		{
			// looking for position
			mid = left + (right - left) / 2;
					
			if (looser_to_insert.first > main_chain[mid].first)
				left = mid;
			else
				right = mid;
			// insert element
			if (looser_index == loosers_chain.size() - 1 && odd == 1 && right == main_chain.size() \
				&& right - left == 1 && looser_to_insert.first > main_chain[winner_index_in_main_chain].first)
			{
				main_chain.push_back(looser_to_insert);
				break ;
			}
			if (right - left == 1 || right - left == 0)
			{	
				typename Container::iterator it = main_chain.begin(); 
				main_chain.insert(it + right, looser_to_insert);
				break ;
			}
		}
		if (odd == 1 && looser_index == loosers_chain.size() - 1)
			continue ;

		
		// NEXT LOOSER INDEX SELECTION

		
		// Set winner_index_in_main_chain	
		range++;
			// Using jacobsthal sequence to reset the winner_index_in_main_chain
		if  (winner_index_in_main_chain == jacobsthal_sequence[0] || \
			range == jacobsthal_sequence[j_index] - jacobsthal_sequence[j_index - 1])
		{
			j_index++;
			// looking for next winner_index in main chain including elements 
			winner_index_in_main_chain = jacobsthal_sequence[j_index] + jacobsthal_sequence[j_index - 1] + 1;
			if (winner_index_in_main_chain > main_chain.size() - 1) // handle when number is odd
				winner_index_in_main_chain = main_chain.size() - 1;
			range = 0;
			continue ;
		}
		// iterate the winner index if don't need to reset
		
		// looking for new winner_index
		if (winner_index_in_main_chain == right)
			winner_index_in_main_chain --;
		while (main_chain[winner_index_in_main_chain].second.empty())
		{
			winner_index_in_main_chain --;
		}
	}
	return (main_chain);
}

#endif
