/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:18:41 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 13:56:34 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
					ScavTrap(void);
					ScavTrap(const ScavTrap& src);
					~ScavTrap(void);
		ScavTrap& 	operator=(const ScavTrap& src);

	public:
					ScavTrap(std::string name);
		void 		guardGate(void) const;
		void		attack(const std::string& target);
};

#endif
