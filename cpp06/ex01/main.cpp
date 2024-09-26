/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:03:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/18 16:51:05 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data dtest;
	dtest.data1 = 2;
	dtest.data2 = 'c';
	dtest.data3 = 2.44;
	
	std::cout << &dtest << std::endl;
	uintptr_t ser = Serializer::serialize(&dtest);
	std::cout << ser << std::endl;
	Data *pt_dtest = Serializer::deserialize(ser);
	std::cout << pt_dtest << std::endl;
	std::cout << pt_dtest->data3 << std::endl;
	return (0);
}