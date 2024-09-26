/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:33:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/26 17:15:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{	
	try
	{
		std::vector<int> l;
		l.push_back(2);
		l.push_back(8);
		l.push_back(19);
		l.push_back(1);

		easyfind(l, 19);
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
