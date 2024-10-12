/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:18:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/12 18:12:30 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_time_comparison(std::clock_t& start1, std::clock_t& end1, std::clock_t& start2, std::clock_t& end2, size_t size)
{
	double time_deque;
	double time_vector;
	
	time_deque = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;
	time_vector = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << size << " elements with std::deque: " << time_deque << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::vector: " << time_vector << " us" << std::endl;
}

void	print_after_sorting(std::deque<iint>& deque_unsorted_chain)
{
	std::cout << "After: ";
	for (std::deque<iint>::iterator it = deque_unsorted_chain.begin(); it != deque_unsorted_chain.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
}

void	print_before_sorting(std::deque<iint>& deque_unsorted_chain)
{
	std::cout << "Before: ";
	for (std::deque<iint>::iterator it = deque_unsorted_chain.begin(); it != deque_unsorted_chain.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	std::vector<iint> 	vector_unsorted_chain;
	std::deque<iint> 	deque_unsorted_chain;
	std::deque<iint> 	deque_sorted_chain;
	std::clock_t 		start1, end1;
	std::clock_t 		start2, end2;

	if (ac < 2)
	{
		std::cerr << "2 minimum args are required!" << std::endl;
		return (1);
	}
	av++;
	try
	{
		PmergeMe sorter;
		sorter.store_chain_in_container(vector_unsorted_chain, av);
		sorter.store_chain_in_container(deque_unsorted_chain, av);
		start1 = std::clock();
		deque_sorted_chain = sorter.ford_johnson_sorting_algorithm(deque_unsorted_chain, 0);	
		end1 = std::clock();
 		start2 = std::clock();
 		sorter.ford_johnson_sorting_algorithm(vector_unsorted_chain, 0);
		end2 = std::clock();
		print_before_sorting(deque_unsorted_chain);
		print_after_sorting(deque_sorted_chain);
		print_time_comparison(start1, end1, start2, end2, deque_unsorted_chain.size());	
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}