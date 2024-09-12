/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:32:56 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 15:49:54 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
					WrongCat(void);
					~WrongCat(void);
					WrongCat(const WrongCat& src);
		WrongCat& 	operator=(const WrongCat& src);
		void		makeSound(void) const;
};

#endif
