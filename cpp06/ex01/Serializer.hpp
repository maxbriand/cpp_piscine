/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:23:32 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 16:19:34 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>

class Serializer
{	
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
};

#endif
