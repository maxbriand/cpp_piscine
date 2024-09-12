/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:22:05 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 16:47:29 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
						Animal(void);
						Animal(const Animal& src);
		virtual			~Animal(void);
		Animal&			operator=(const Animal& src);
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string		_type;
};

#endif
