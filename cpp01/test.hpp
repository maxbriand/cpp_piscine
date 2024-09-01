/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:51:58 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 15:33:24 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include <string>
#include <fstream>

class	Test
{
	public:
		Test(void);
		~Test(void);
		int get_i(void);
	private:
		int	_i;
};

#endif