/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:51:28 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 16:51:42 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:
							Weapon(void);
							Weapon(std::string type);
							~Weapon(void);
		void 				setType(std::string type);
		const std::string&	getType(void);

	private:
		std::string			_type;
};

#endif
