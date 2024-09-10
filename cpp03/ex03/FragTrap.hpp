/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:02:31 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 22:20:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
					FragTrap(void);
					FragTrap(const FragTrap& src);
					~FragTrap(void);
		FragTrap& 	operator=(const FragTrap& src);

	public:
					FragTrap(std::string name);
		void		highFivesGuys(void) const;
	// protected:
	// 	unsigned int	_hit_pointsf;
	// 	unsigned int	_energy_pointsf;
	// 	unsigned int	_attack_damagef;
};

#endif
