/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:58:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/03 15:52:50 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"


int	main(void)
{
	std::string hello = "hello world!";
	int i = 0;

	size_t pos = 5;
	pos += hello.find("okok");
	if (pos == std::string::npos)
	{
		std::cout << "hello" << std::endl;
		return (0);
	}
	std::cout << "caz pos is: " << pos << std::endl;


	while (hello[i])
	{
		// std::cout << hello[i] << std::endl;
		i++;	
	}
	// i++;
	std::cout << hello.substr(i) << std::endl;
	if (hello.substr(i).empty())
		std::cout << "empty" << std::endl;
	// std::cout << hello[i] << std::endl;
	return (0);
}
