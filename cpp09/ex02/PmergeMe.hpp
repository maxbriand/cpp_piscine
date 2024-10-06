/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:23:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/05 17:08:03 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <string>

class PmergeMe 
{
   public:
		void	merge_insert_sort(std::string input);
		class WrongInputException : public std::exception {const char* what() const throw();};

   private:
	   // variables

   public:
	   PmergeMe();
	   PmergeMe(const PmergeMe& other);
	   PmergeMe& operator=(const PmergeMe& other);
	   ~PmergeMe();
};

#endif
