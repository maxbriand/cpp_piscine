/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:18:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/09 18:59:21 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// check recursivity limit AND add the limit if it's under than 1 million
// check constructors
int	main(int ac, char **av)
{
	std::vector<iint>	vector_unsorted_chain;
	std::deque<iint>	deque_unsorted_chain;

	if (ac < 2){
		std::cerr << "2 minimum args are required!" << std::endl; return (1);}
	av++;
	try
	{
		PmergeMe sorter;


		sorter.store_chain_in_container(vector_unsorted_chain, av);
		
		// Step 1.5: Create the positive int deque sequence
		// std::vector<iint> vector_unsorted_sequence = sorter


		// Step 2: Sort the vector sequence
		// sorter.merge_insert_sort(av);

		// Step 2.5: Sort the deque sequence
	
	
	
	
	// Parsing: only positive numbers in the input // max 10000?
	// put a limit on 10000 integers
	//  

	// Output:
	// Before: 141 79 526 321 [...]
	// After: 79 141 321 526 [...]
	// Time to process a range of 3000 elements with std::[..] : 62.14389 us
	// Time to process a range of 3000 elements with std::[..] : 69.27212 us

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}