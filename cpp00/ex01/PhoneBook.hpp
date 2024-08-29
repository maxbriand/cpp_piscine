/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:19:12 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/30 00:26:39 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>


class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		Contact list[8];
		void add(void);
		void search(void);
		int next_index;
		// void step_by_step(void); // cut the progran
};

#endif
