/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:23:23 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 16:49:35 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;	
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called" << std::endl;	
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brain Copy assignent operator called" << std::endl;
	for (int i = 0; i < 100; ++i)
                _ideas[i] = src._ideas[i];
	return (*this);
}

