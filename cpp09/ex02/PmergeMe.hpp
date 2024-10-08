/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/08 17:07:29 by mbriand          ###   ########.fr       */
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

typedef	std::pair<int, std::vector<int> >iint;

class PmergeMe 
{
   public:
		void	merge_insert_sort(char ** input);
		class WrongInputException : public std::exception {const char* what() const throw();};

   private:
		void	store_int_in_deque(std::deque <iint>& unsorted_chain, char** input);
		void	duplicate_numbers_check(std::deque<iint>& initial_sequence);
		std::deque<iint>	ford_johnson_sorting_algorithm(std::deque<iint>& unsorted_chain, int level);

   public:
	   PmergeMe();
	   PmergeMe(const PmergeMe& other);
	   PmergeMe& operator=(const PmergeMe& other);
	   ~PmergeMe();
};

#endif
