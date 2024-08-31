/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:37:38 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 14:58:05 by mbriand          ###   ########.fr       */
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

void    PhoneBook::add(void)
{
	std::string input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	this->list[this->next_index].set_first_name(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	this->list[this->next_index].set_last_name(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	this->list[this->next_index].set_nickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	this->list[this->next_index].set_phone_number(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	this->list[this->next_index].set_darkest_secret(input);
	if (this->next_index == 7)
		this->next_index = 0;
	else
		this->next_index++;
	return ;
}

void    PhoneBook::show_column_type(void)
{
	std::cout << std::setw(10) << "Index" << "|" << "First name" << "|" <<
		std::setw(10) << "Last name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
}

void    PhoneBook::display_list(void)
{
	int	i;
	std::string elem;

	i = 0;
	while (i < 8)
	{
		std::cout << std::setw(10) << this->list[i].index << "|";
		elem = this->list[i].get_first_name();
		if (elem.size() <= 10)
			std::cout << std::setw(10) << elem << "|";
		else
			std::cout << elem.substr(0, 9) << "." << "|";
		elem = this->list[i].get_last_name();
		if (elem.size() <= 10)
			std::cout << std::setw(10) << elem << "|";
		else
			std::cout << elem.substr(0, 9) << "." << "|";
		elem = this->list[i].get_nickname();
		if (elem.size() <= 10)
			std::cout << std::setw(10) << elem << "|" << std::endl ;
		else
			std::cout << elem.substr(0, 9) << "." << "|" << std::endl;
		i++;
	}
}

void	PhoneBook::display_contact(int i)
{
	i--;

	std::cout << i + 1 << std::endl;
	std::cout << "First name: " << this->list[i].get_first_name() << std::endl;
	std::cout << "Last name: " << this->list[i].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->list[i].get_nickname() << std::endl;
}

void    PhoneBook::search(void)
{
	int i;
	std::string index;

	this->show_column_type();
	this->display_list();
	
	std::cout << "Contact index: ";
	std::getline(std::cin, index);
	i = std::atoi(index.c_str());
	if (i < 1 || i > 8)
	{
		std::cout << "invalid scope (scope: 1 to 8)" << std::endl;
		return ;
	}
	this->display_contact(i);
}
