/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:29:05 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/03 19:33:36 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	errmsg(std::string msg)
{
	std::cout << msg << std::endl;
	return (1);
}

int	main(int ac, char **av)
{
	std::string level;
	Harl		Harl;

	if (ac < 2 || ac > 2)
		return (errmsg("You have to pass one parameter"));
	level = av[1];
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
		return (errmsg("This Harl level doesn't exist"));
	Harl.complain(level);
	return (0);
}
