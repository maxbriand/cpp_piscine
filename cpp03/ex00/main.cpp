/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:08:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/07 18:11:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap p1("Charizard");
	p1.attack("Pikachu");
	std::cout << "Hit points: " << p1.getHitPoints() << std::endl;
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;
	p1.attack("Pikachu");
	p1.attack("Pikachu");
	p1.takeDamage(5);
	p1.attack("Pikachu");
	p1.beRepaired(1);
	p1.attack("Pikachu");
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;
	p1.takeDamage(5);
	p1.attack("Pikachu");
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << p1.getHitPoints() << std::endl;
	p1.takeDamage(5);
	std::cout << "Hit points: " << p1.getHitPoints() << std::endl;
	p1.attack("Pikachu");
	return (0);
}
