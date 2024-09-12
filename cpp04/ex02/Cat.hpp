/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:32:56 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/11 15:16:14 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
				Cat(void);
				~Cat(void);
				Cat(const Cat& src);
		Cat& 	operator=(const Cat& src);
		void	makeSound(void) const;
	private:
		Brain*	_brain;
};

#endif
