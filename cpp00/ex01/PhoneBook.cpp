/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:37:38 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/29 19:58:07 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    next_index = 0;
}

PhoneBook::~PhoneBook(void){}

void    PhoneBook::add(void)
{
    this->list[this->next_index].first_name = "hey";

    if (this->next_index == 7)
        next_index = 0;
    else
        next_index++;
    return ;
}

void    PhoneBook::search(void)
{
    int i;

    i = -1;
    while (i++ < 8)
    {
        std::cout << std::setw(10) << this->list[i].index << " | ";
        std::cout << std::setw(10) << this->list[i].first_name << " | ";
        std::cout << std::setw(10) << this->list[i].last_name << " | ";
        std::cout << std::setw(10) << this->list[i].nickname << std::endl;
    }
    return ;
}
