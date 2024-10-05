/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:38:15 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/05 15:35:55 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{

	if (ac < 2 || ac > 2){
		std::cerr << "Incorrect argument number!" << std::endl; return (1);}
	try
	{
		RPN calculator;
		std::cout << calculator.calcul_processing(av[1]) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
