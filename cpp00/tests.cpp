/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:53:10 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/30 15:57:02 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string input;

    while (1) {
        std::cout << "Enter command: ";
        std::cin >> input;

        if (std::cin.eof()) {
            std::cin.clear();  // Clear the EOF flag
            std::cout << "\nEOF detected. Please enter a command." << std::endl;
            continue;  // Continue the loop to prompt for input again
        } 
		else if (std::cin.fail()) {
            std::cin.clear();  // Clear any other fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining input
            std::cout << "Input error. Please try again." << std::endl;
            continue;  // Continue the loop to prompt for input again
        } 
		else if (input == "EXIT") {
            break;
        } 
		else if (input == "ADD") {
            // pb.add();
        } 
		else if (input == "SEARCH") {
            // pb.search();
        } 
		else {
            std::cout << "Unknown command" << std::endl;
        }
    }

    return 0;
}

