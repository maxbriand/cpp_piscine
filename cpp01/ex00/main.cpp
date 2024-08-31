/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:59:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 18:28:45 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zomb;
	
	zomb = newZombie("zioup");
	zomb->announce();
	randomChump("bloup");
	delete zomb;
	return (0);
}
