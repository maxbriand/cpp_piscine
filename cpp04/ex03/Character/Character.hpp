/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/16 13:18:06 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria*			_inventory[4];
		std::string			_name;
		AMateria*			_ground;
	public:
							Character(void);
							Character(const Character& src);
							~Character(void);
		Character&			operator=(const Character& src);	
	public:
							Character(const std::string& name);
		const std::string& 	getName(void) const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
};

#endif
