/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:37:38 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/30 16:08:00 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
    std::cout << "First name: ";
    std::cin >> this->list[this->next_index].first_name;
    std::cout << "Last name: ";
    std::cin >> this->list[this->next_index].last_name;
    std::cout << "Nickname: ";
    std::cin >> this->list[this->next_index].nickname;
    std::cout << "Darkest secret: ";
    std::cin >> this->list[this->next_index].darkest_secret;
    if (this->next_index == 7)
        this->next_index = 0;
    else
        this->next_index++;
    return ;
}

// void    PhoneBook::step_by_step(void)
// {
// }

// cut the program

void    PhoneBook::show_column_type(void)
{
    std::cout << std::setw(10) << "Index" << "|" << "First name" << "|" <<
        std::setw(10) << "Last name " << "|" << "Nickname" << std::endl;
}

void    PhoneBook::search(void)
{
    int i;
    std::string elem;

    this->show_column_type();
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
    return ;
}
