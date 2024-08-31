/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:28:46 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 23:40:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		Hi;
	std::string*	stringPTR;
	std::string&	stringREF = Hi;

	Hi = "HI THIS IS BRAIN";
	stringPTR = &Hi;
	std::cout << "The memory adress of the string variable: " << &Hi << std::endl;	
	std::cout << "The memory adress held by stringPTR: " << stringPTR << std::endl;	
	std::cout << "The memory adress held by stringREF: " << &stringREF << std::endl;	
	std::cout << "The value of the string variable: " << Hi << std::endl;	
	std::cout << "The value pointed by stringPTR: " << *stringPTR << std::endl;	
	std::cout << "The value pointed by stringREF: " << stringREF << std::endl;	
	return (0);
}
