/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:19:12 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/28 23:58:27 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		Contact list[8];
		// void add(void);
		// void search(void);
		int test = 2;
};

#endif