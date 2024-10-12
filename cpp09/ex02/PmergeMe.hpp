/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/12 17:48:54 by mbriand          ###   ########.fr       */
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
# include <iterator>   // for std::distance
# include <algorithm> // for std::find

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
		template <typename Container>
		void	sort_looser_chain(Container& unsorted_looser_chain, Container& sorted_looser_chain, Container& main_chain , int level);
		template <typename Container>
		void	binary_search(Container &main_chain, iint& element_to_insert, size_t& right);
		size_t	update_looser_pos(size_t pos, size_t looser_chain_size, size_t& jacobsthal_index);

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
void	PmergeMe::sort_looser_chain(Container& unsorted_looser_chain, Container& sorted_looser_chain, Container& main_chain, int level)
{
	typename Container::iterator it = main_chain.begin(); 
	while (it != main_chain.end())
	{
		sorted_looser_chain.push_back(unsorted_looser_chain[it->second[level]]);
		it++;
	}
	if (main_chain.size() != unsorted_looser_chain.size())
		sorted_looser_chain.push_back(unsorted_looser_chain.back());
}

template <typename Container>
void	PmergeMe::binary_search(Container &main_chain, iint& element_to_insert, size_t& right)
{
	size_t	left = 0;
	size_t	mid = 0;	

    if (element_to_insert.first < main_chain.front().first)
    {
        main_chain.insert(main_chain.begin(), element_to_insert);
        return;
    }
	while (1)
	{
		mid = left + (right - left) / 2;
		if (element_to_insert.first > main_chain[mid].first)
			left = mid;
		else
			right = mid;
		if (right - left == 1)
		{
			main_chain.insert(main_chain.begin() + right, element_to_insert);
			break ;
		}
	}
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
	size_t		pos = 0;
	size_t		right = 0;
	iint		element_to_insert;
	Container	initial_main_chain = main_chain;
	Container	sorted_looser_chain;
	size_t		jacobsthal_index = 0;

	sort_looser_chain(loosers_chain, sorted_looser_chain, initial_main_chain, level);
	// int	its_the_print = 0; 	// to delete 
	// std::cout << std::endl << RED << "New level";

	while (main_chain.size() < unsorted_chain.size())
	{
// 		if (its_the_print == 0)
// {
// 	std::cout << BLU << std::endl << "New loop: " << CLR << std::endl;
// 	std::cout << "Unsorted elements: ";
// 	for (typename Container::iterator it = unsorted_chain.begin(); it != unsorted_chain.end(); ++it)
// 	{
// 		std::cout << it->first << " ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << "Initial main chain: ";
// 	for (typename Container::iterator it = initial_main_chain.begin(); it != initial_main_chain.end(); ++it)
// 	{
// 		std::cout << it->first << " ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << "Sorted Looser Chain: ";
// 	for (typename Container::iterator it = sorted_looser_chain.begin(); it != sorted_looser_chain.end(); ++it)
// 	{
// 		std::cout << it->first << " ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << YLW"Main chain" << ": ";
// 	for (typename Container::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
// 	{
// 		std::cout << it->first << " ";
// 	}
// 	std::cout << std::endl<<CLR;
// 	std::cout << "The current position is: " << pos << std::endl;		
// }

		
		if (pos == 0)
		{
			main_chain.insert(main_chain.begin(), sorted_looser_chain[0]);
		}
		else if (sorted_looser_chain.size() - 1 == pos && loosers_chain.size() != winners_chain.size())
		{
			element_to_insert = loosers_chain.back();
			if (element_to_insert.first < main_chain.back().first)
			{
				right = main_chain.size() - 1;
				binary_search(main_chain, element_to_insert, right);
			}
			else
			{
				main_chain.push_back(element_to_insert);
			}
		}
		else
		{
			element_to_insert = sorted_looser_chain[pos];
			typename Container::iterator it = std::find(main_chain.begin(), main_chain.end(), initial_main_chain[pos]);
			right = std::distance(main_chain.begin(), it);
			binary_search(main_chain, element_to_insert, right);
		}
		// Update index element to add in looser chain
		pos = update_looser_pos(pos, sorted_looser_chain.size() - 1, jacobsthal_index);
	}
	return (main_chain);
}

#endif
