/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:53:44 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/14 16:45:58 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
					Ice(void);
					~Ice(void);
					Ice(const Ice& src);
		Ice& 		operator=(const Ice& src);

	public:
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
