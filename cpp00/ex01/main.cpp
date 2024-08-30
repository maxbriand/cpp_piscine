/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:37:23 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/30 18:19:10 by mbriand          ###   ########.fr       */
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
        if (std::cin.eof())
            break ;
        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        // if (std::cin.eof())
        //     break ;
        if (input == "EXIT")
            break ;
        else if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
            pb.search();
        else if (!std::cin.eof())
            std::cout << "unknows command" << std::endl;
    }
    return (0);
}
