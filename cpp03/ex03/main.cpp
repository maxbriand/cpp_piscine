/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:08:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 14:44:17 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap *p1 = new DiamondTrap();
	std::cout << std::endl;
	std::cout << "P1 output:" << std::endl;
	p1->whoAmI();
	std::cout << "p1 hit points: " << p1->getHitPoints() << std::endl;
	std::cout << "p1 energy points: " << p1->getEnergyPoints() << std::endl;
	p1->attack("Pikachu");
	std::cout << std::endl;
	delete p1;
	std::cout << std::endl << std::endl;

	DiamondTrap *p2 = new DiamondTrap("Charizard");
	std::cout << std::endl;
	std::cout << "P2 output:" << std::endl;
	p2->whoAmI();
	std::cout << "p2 hit points: " << p2->getHitPoints() << std::endl;
	std::cout << "p2 energy points: " << p2->getEnergyPoints() << std::endl;
	p2->attack("Pikachu");
	std::cout << std::endl;
	delete p2;
	std::cout << std::endl << std::endl;

	DiamondTrap p4("Poke");
	std::cout << std::endl;
	DiamondTrap p3 = p4;
	std::cout << std::endl << std::endl;
	std::cout << "P3 output:" << std::endl;
	p3.whoAmI();
	std::cout << "p3 hit points: " << p3.getHitPoints() << std::endl;
	std::cout << "p3 energy points: " << p3.getEnergyPoints() << std::endl;
	p3.attack("Mon");

	std::cout << std::endl << std::endl;
	return (0);
}
