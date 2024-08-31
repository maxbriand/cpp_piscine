/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:39:04 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 23:24:52 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde;
	int		i;

	horde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}	
	return(horde);
}
