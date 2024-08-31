/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:19:15 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 14:42:18 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		int			index;
		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		// std::string get_phone_number(void);
		// std::string get_darkest_secret(void);
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string _phone_number;	
		std::string _darkest_secret;	
};

#endif