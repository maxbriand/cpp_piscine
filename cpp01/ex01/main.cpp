/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:36:32 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 23:26:08 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* horde;
	int		N;
	int		i;

	i = 0;
	N = 22;
	if (N < 0)
		return (0);
	horde = zombieHorde(N, "John");
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return (0);
}
