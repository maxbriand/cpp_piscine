/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:39:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 16:47:57 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
				Dog(void);
				~Dog(void);
				Dog(const Dog& src);
		Dog& 	operator=(const Dog& src);
		void	makeSound(void) const;
	private:
		Brain*	_brain;
};

#endif
