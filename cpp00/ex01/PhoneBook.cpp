/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:37:38 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/30 18:19:36 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	int i;
	
	next_index = 0;
	i = 0;
	while (i < 8)
	{
		this->list[i].index = i + 1;
		i++;
	}
}

PhoneBook::~PhoneBook(void){}

// protect EOF
void    PhoneBook::add(void)
{
	std::string input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		break ;
	this->list[this->next_index].set_first_name(input);
	std::cout << "Last name: ";
	std::cin >> this->list[this->next_index].la;
	std::cout << "Nickname: ";
	std::cin >> this->list[this->next_index].nickname;
	std::cout << "Phone number: ";
	std::cin >> this->list[this->next_index].phone_number;
	std::cout << "Darkest secret: ";
	std::cin >> this->list[this->next_index].darkest_secret;
	if (this->next_index == 7)
		this->next_index = 0;
	else
		this->next_index++;
	return ;
}

void    PhoneBook::show_column_type(void)
{
	std::cout << std::setw(10) << "Index" << "|" << "First name" << "|" <<
		std::setw(10) << "Last name " << "|" << "Nickname" << std::endl;
}

void    PhoneBook::display_list(void)
{
	int	i;
	std::string elem;

	i = 0;
	while (i < 8)
	{
		std::cout << std::setw(10) << this->list[i].index << "|";
		elem = this->list[i].first_name;
		if (elem.size() <= 10)
			std::cout << std::setw(10) << elem << "|";
		else
			std::cout << elem.substr(0, 9) << "." << "|";
		elem = this->list[i].last_name;
		if (elem.size() <= 10)
			std::cout << std::setw(10) << elem << "|";
		else
			std::cout << elem.substr(0, 9) << "." << "|";
		elem = this->list[i].nickname;
		if (elem.size() <= 10)
			std::cout << std::setw(10) << elem << std::endl;
		else
			std::cout << elem.substr(0, 9) << "." << std::endl;
		i++;
	}
}

// void	PhoneBook::display_contact(int i)
// {
// 	i--;

// 	this->list[i].first_name;
// }

void    PhoneBook::search(void)
{
	int i;
	std::string index;

	this->show_column_type();
	this->display_list();
	
	std::getline(std::cin, index);
	// convert using atoi and don't forget to protect -1;
	i = std::atoi(index.c_str());
	if (i < 1 || i > 8)
	{
		std::cout << "invalid scope (scope: 1 to 8)" << std::endl;
		return ;
	}
	this->display_contact(i);
}
