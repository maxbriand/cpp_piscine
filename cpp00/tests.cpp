/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:53:10 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/29 23:45:16 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test.hpp"

int main(void)
{
	std::string hello;

	hello = "mamamammam";
	hello = "okokokokokokokokoko";
	std::cout << "'" << hello << "'" << std::endl;
	if (hello == "")
		std::cout << "hello world!" << std::endl;
	return (0);
}
