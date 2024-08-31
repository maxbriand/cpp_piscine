/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:37:04 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 23:05:15 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	public:
					Zombie(void);
					~Zombie(void);
		void		set_name(std::string name);
		std::string	get_name(void);
		void		announce(void);

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
