/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:40:04 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 19:39:12 by mbriand          ###   ########.fr       */
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
        void        attack(void);
        void        set_name(std::string name);
        std::string get_name(void);
        void        setWeapon(Weapon &player_weapon);
        Weapon&     getWeapon(void);
    private:
        Weapon      _player_weapon;
        std::string _name;
};

#endif
