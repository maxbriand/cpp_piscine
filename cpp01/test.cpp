/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:58:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 15:33:58 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

Test::Test(void)
{
	this->_i = 8;	
}

Test::~Test(void){}

int Test::get_i(void)
{
	return(this->_i);
}

int	main(void)
{
	Test hello;
	
	const int ok = hello.get_i();
	// ok = 9;
	std::cout << "the value of ok is: " << ok << std::endl;
	return (0);
}
