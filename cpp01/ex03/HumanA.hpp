/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:40:04 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 23:34:27 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	public:
					HumanA(std::string name, Weapon& club);
					~HumanA(void);
		void		attack(void) const;
	private:
		Weapon&		_weapon;
		std::string _name;
};

#endif
