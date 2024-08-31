/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:00:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 18:08:21 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie 		*newZombie(std::string name)
{
	Zombie	*one;

	one = new Zombie();
	one->set_name(name);
	return (one);
}
