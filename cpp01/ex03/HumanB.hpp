/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:50:15 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 23:46:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"
# include <iostream>

class HumanB
{
    public:
        			HumanB(std::string name);
        			~HumanB(void);
        void        setWeapon(Weapon& player_weapon);
        void        attack(void) const;
    private:
        Weapon*		_weapon;
        std::string _name;            
};

#endif
