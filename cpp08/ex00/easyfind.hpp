/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:49:43 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/26 14:17:07 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <list>
# include <iostream>
# include <algorithm>

template <typename T>
int	easyfind (T content, int i)
{
	int index = std::find(content.begin(), content.end(), i);
	std::cout << index << "value" << std::endl;
	return (-1);
}


#endif