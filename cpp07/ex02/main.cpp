/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:36:12 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/26 13:13:21 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

int main() 
{
    try {
        // Test: Create an empty array
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test: Create an array with 5 elements
        Array<int> intArray(5);
        std::cout << "intArray size: " << intArray.size() << std::endl;

        // Fill the array with values
        for (unsigned int i = 0; i < intArray.size(); i++) 
		{
            intArray[i] = i * 10;
        }

        // Output the values in the array
        std::cout << "intArray values: ";
        for (unsigned int i = 0; i < intArray.size(); i++) 
		{
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test: Copy constructor
        Array<int> copyArray(intArray);
        std::cout << "Copy array size: " << copyArray.size() << std::endl;
        std::cout << "Copy array values: ";
        for (unsigned int i = 0; i < copyArray.size(); i++) 
		{
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl;

        // Test: Assignment operator
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        std::cout << "Assigned array values: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++) 
		{
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test: Array bounds checking
        std::cout << "Accessing an out-of-bounds element in intArray: ";
        std::cout << intArray[5] << std::endl;

    } 
	catch (const std::exception& e) 
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
