/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:50:15 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 19:33:04 by mbriand          ###   ########.fr       */
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
        void        attack(void);
        void        set_name(std::string name);
        std::string get_name(void);
        void        setWeapon(Weapon& player_weapon);
        Weapon&     getWeapon(void);
    private:
        Weapon      _player_weapon;
        std::string _name;            
};

#endif
