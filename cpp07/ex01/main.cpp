/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:35:45 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/25 19:42:05 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename G>
void	mult_by_2(G& i)
{
	i *= 2;
}

int main(void)
{
	int arrint[4] = {55, 34, 8, 4};

	iter(arrint, 5, mult_by_2<int>);
	std::cout << arrint[2] << std::endl;
	return (0);
}

