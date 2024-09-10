/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:40:27 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 15:08:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
					DiamondTrap(void);
					DiamondTrap(const DiamondTrap& src);
					~DiamondTrap(void);
		DiamondTrap& 	operator=(const DiamondTrap& src);

	public:
					DiamondTrap(std::string name);
		void		whoAmI(void) const;
		std::string	getName(void) const;

	private:
		std::string _name;
};

#endif
