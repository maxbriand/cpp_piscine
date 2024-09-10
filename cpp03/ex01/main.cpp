/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:08:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 22:02:24 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	useAttack(ClapTrap *player)
{
	player->attack("Pikachu");
}

int	main(void)
{
	ScavTrap p1("Charizard");
	std::cout << "Name: " << p1.getName() << std::endl;
	std::cout << "Hit points: " << p1.getHitPoints() << std::endl;
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;
	p1.guardGate();
	p1.attack("Pikachu");
	p1.beRepaired(1);
	useAttack(&p1);
	std::cout << "Hit points: " << p1.getHitPoints() << std::endl;
	std::cout << "Energy points: " << p1.getEnergyPoints() << std::endl;
	ScavTrap p2 = p1;
	std::cout << "Name: " << p2.getName() << std::endl;
	std::cout << "Hit points: " << p2.getHitPoints() << std::endl;
	std::cout << "Energy points: " << p2.getEnergyPoints() << std::endl;
	p2.guardGate();
	p2.attack("Pikachu");
	p2.beRepaired(1);
	std::cout << "Hit points: " << p2.getHitPoints() << std::endl;
	std::cout << "Energy points: " << p2.getEnergyPoints() << std::endl;
	return (0);
}
