/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:08:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 15:45:22 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap p1("Charizard");
	std::cout << "Name: " << p1.getName() << std::endl;
	std::cout << "Hit points: " << p1.getHitPoints() << std::endl;
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;
	p1.attack("Pikachu");
	p1.beRepaired(1);
	p1.highFivesGuys();
	std::cout << "Hit points: " << p1.getHitPoints() << std::endl;
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;

	// FragTrap p2 = p1;
	// std::cout << "Name: " << p2.getName() << std::endl;
	// std::cout << "Hit points: " << p2.getHitPoints() << std::endl;
	// std::cout << "Energy points: " << p2.getEnergyPoints() << std::endl;
	// p2.attack("Pikachu");
	// p2.beRepaired(1);
	// p2.highFivesGuys();
	// std::cout << "Hit points: " << p2.getHitPoints() << std::endl;
	// std::cout << "Energy points: " << p2.getEnergyPoints() << std::endl;

	return (0);
}
