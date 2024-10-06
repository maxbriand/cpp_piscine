/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:18:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/05 16:57:40 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// use deque AND Vector
int	main(int ac, char **av)
{
	if (ac < 3){
		std::cerr << "2 minimum numbers are required!" << std::endl; return (1);}

	try
	{
		PmergeMe	sorter;
		sorter.mer
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

	(void) av; // to delete
	return (0);
}