/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:26:04 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/25 15:10:12 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Whatever_HPP
# define Whatever_HPP

# include <iostream>
# include <string>

template <typename T>
void	swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename U>
U	min(U& a, U&b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename X>
X	max(X& a, X& b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
