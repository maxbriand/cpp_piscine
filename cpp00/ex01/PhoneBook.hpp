/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:19:12 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/30 17:07:41 by mbriand          ###   ########.fr       */
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
		void 	add(void);
		void 	search(void);
		void	show_column_type(void);
		void	display_list(void);
		void	display_contact(int i);
		int 	next_index;
};

#endif
