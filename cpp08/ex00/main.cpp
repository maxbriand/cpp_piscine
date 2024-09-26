/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:33:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/26 14:10:54 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	int pos;
	
	std::list<int> l;
	l.push_back(2);
	l.push_back(8);
	l.push_back(19);
	l.push_back(1);

	pos = easyfind(l, 3);
	std::cout << pos << std::endl;
	return (0);
}
