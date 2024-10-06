/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:52:40 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/28 13:58:47 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() 
		{
			return std::stack<T>::c.begin();
		}
		iterator end() 
		{
			return std::stack<T>::c.end();
		}

	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other) 
		{
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}
};

#endif
