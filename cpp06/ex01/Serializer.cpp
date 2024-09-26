/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:24:17 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 16:28:58 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::~Serializer(){}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& src)
{
	*this = src;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (&other != this)
		return (*this);
	return (*this);
}
