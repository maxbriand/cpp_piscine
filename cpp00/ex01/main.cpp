/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:37:23 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/29 19:22:24 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::string input;
    PhoneBook   pb;

    while (1)
    {
        std::cin >> input;
        if (input == "EXIT")
            break ;
        if (input == "ADD")
            pb.add();
        if (input == "SEARCH")
            pb.search();
    }
    return (0);
}
