/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:22:05 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 15:51:48 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
						WrongAnimal(void);
						WrongAnimal(const WrongAnimal& src);
						~WrongAnimal(void);
		WrongAnimal&	operator=(const WrongAnimal& src);
		std::string		getType(void) const;
		void			makeSound(void) const;
	protected:
		std::string		_type;
};

#endif
