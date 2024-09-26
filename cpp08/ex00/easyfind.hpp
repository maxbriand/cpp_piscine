/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:49:43 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/26 17:13:58 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <iostream>
# include <algorithm>
# include <iterator>

template <typename T>
void easyfind (T content, int i)
{
	int	index;
	
	typename T::iterator it = std::find(content.begin(), content.end(), i);	
	if (it != content.end())
		index = std::distance(content.begin(), it);
	else
		throw std::exception();
	std::cout << i << " is int the list at index: " << index << std::endl;
}

#endif