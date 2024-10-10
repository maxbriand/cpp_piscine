/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/09 18:22:45 by mbriand          ###   ########.fr       */
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
		// Container	ford_johnson_sorting_algorithm(Container& unsorted_chain, int level);
		class WrongInputException : public std::exception {const char* what() const throw();};
		template <typename Container>
		void	store_chain_in_container(Container& unsorted_chain, char** input);

   private:
		template <typename Container>
		void		duplicate_numbers_check(Container& unsorted_chain);

   public:
	   PmergeMe();
	   PmergeMe(const PmergeMe& other);
	   PmergeMe& operator=(const PmergeMe& other);
	   ~PmergeMe();
};

#endif
