/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:14:47 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 18:04:14 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	public:
					Zombie(void);
					~Zombie(void);
		void		announce(void);
		void		set_name(std::string);
		std::string	get_name(void);

	private:
		std::string	_name;
};

Zombie 		*newZombie( std::string name );		
void		randomChump( std::string name );

#endif
