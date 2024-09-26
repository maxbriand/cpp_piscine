/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:03:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/18 16:15:31 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << RED << "Invalid argument number!" << CLR << std::endl; return (1);}
	ScalarConverter::convert(av[1]);
	return (0);
}