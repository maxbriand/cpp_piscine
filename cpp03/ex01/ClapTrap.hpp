/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:08:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 16:32:45 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& src);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& src);

	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
						ClapTrap(std::string name);
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		void			setHitPoints(unsigned int amount);
		void			setEnergyPoints(unsigned int amount);
		std::string		getName(void) const;
};

#endif
