/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:33:23 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/03 19:59:14 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->ptfunct[0] = &Harl::debug;
	this->ptfunct[1] = &Harl::info;
	this->ptfunct[2] = &Harl::warning;
	this->ptfunct[3] = &Harl::error;
}

Harl::~Harl(void){}

void	Harl::debug(void) const
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup \
burger. I really do!" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon \
in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years \
whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;	
}

void	Harl::complain(std::string level)
{	
	int	i;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			switch (i)
			{
				case 0:
					(this->*ptfunct[0])();
				case 1:
					(this->*ptfunct[1])();
				case 2:
					(this->*ptfunct[2])();
				case 3:
					(this->*ptfunct[3])();
				break;
			}
		}
		i++;
	}
}
