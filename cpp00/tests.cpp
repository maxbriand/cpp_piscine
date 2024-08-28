/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:53:10 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/28 16:08:47 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test.hpp"

Test::Test(char c, int d) : a(c), b(d)
{
	std::cout << "c and d are equal to: " << this->a << " " << this->b << std::endl;

}

Test::~Test(void)
{
	std::cout << "end" << std::endl;
}

void Test::bar(void)
{
	std::cout << "hey men!" << std::endl;
}

int	main(void)
{
	Test:Test('l', 22);
	return(0);
}
