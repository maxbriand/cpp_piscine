/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:06:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/05 16:04:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>

class RPN 
{
   public:
		float calcul_processing(std::string calcul);
		class ErrorExpressionException : public std::exception {const char* what() const throw();};
		class DivisionByZeroException : public std::exception {const char* what() const throw();};

   private:
		std::stack<float> 	_digits;
		void				parsing(std::string& calcul, size_t& fpos, size_t& lpos);
		void				calculator(std::string& calcul, size_t fpos);

   public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
};

#endif


