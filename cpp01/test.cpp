/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:58:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 17:51:07 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

Test::Test(void){}

Test::~Test(void){}

int	main(void)
{
	std::ifstream test("file_test.out");
	int first;
	int second;
	int ddd;

	test >> first >> second >> ddd;

	std::cout << first << " " << second << " " << ddd << std::endl;
	test.close();
	return(0);
}
