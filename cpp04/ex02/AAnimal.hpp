/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:22:05 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/11 15:20:08 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
						AAnimal(void);
						AAnimal(const AAnimal& src);
		virtual			~AAnimal(void);
		AAnimal&			operator=(const AAnimal& src);
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
	protected:
		std::string		_type;
};

#endif
