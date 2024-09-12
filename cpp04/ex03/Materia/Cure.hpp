/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:53:22 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/12 22:51:39 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
					Cure(void);
					~Cure(void);
					Cure(const Cure& src);
		Cure& 		operator=(const Cure& src);

	public:
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
