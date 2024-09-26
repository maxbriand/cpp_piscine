/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:13:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/25 16:10:27 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>


template <typename T, typename L, typename F>
void	iter(T& array, L lenght, F* fct)
{
	int i = 0;
	
	while (i < lenght)
	{
		fct(array[i]);
		i++;
	}
}

#endif
