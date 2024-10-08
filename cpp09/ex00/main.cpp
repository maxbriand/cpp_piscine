/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:02:31 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/04 22:01:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac > 2 || ac < 2)
		{std::cerr << "Error: Incorrect argument number!" << std::endl; exit (1);}
	try
	{
		// Test: Default construction
		BitcoinExchange bExchanger;
		BitcoinExchange bExchanger3;

		// Test: Copy construction
		BitcoinExchange bExchanger2(bExchanger);

		// Test: operator=
		bExchanger3 = bExchanger;

		// Test Print Portfolio evolution
		bExchanger3.print_bitcoin_portfolio_evolution(av[1]);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}		
	return (0);
}