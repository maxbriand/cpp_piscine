/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:32:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 13:12:18 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string 		_type;

	public:
							AMateria();
							AMateria(const AMateria& src);
							AMateria& operator=(const AMateria& src);
		virtual				~AMateria();

	public:
							AMateria(const std::string& type);
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);
		const std::string& 	getType(void) const;
};

#endif
