/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:17:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/27 14:50:19 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() 
{
    // 1. Basic test: Create a Span with a max capacity of 5 and add some numbers
    try 
	{
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } 
	catch (std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }

    // 2. Test exception when adding a number beyond the capacity
    try 
	{
        Span sp(3);
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40);
    } 
	catch (std::exception &e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 3. Test exception when trying to get spans with not enough numbers
    try 
	{
        Span sp(5);
        sp.addNumber(10);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    } 
	catch (std::exception &e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 4. Test with a large number of elements (10,000 elements)
    try 
	{
        Span sp(10000);
        
        for (int i = 0; i < 10000; ++i) 
		{
            sp.addNumber(i);
        }

        std::cout << "Shortest span (10,000 numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (10,000 numbers): " << sp.longestSpan() << std::endl;
    } 
	catch (std::exception &e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 5. Test using a range of iterators (use addNumbers)
    try 
	{
        Span sp(100);
        std::vector<int> numbers;
        
        for (int i = 1; i <= 100; ++i) 
            numbers.push_back(i * 2);
        sp.addNumbers(&numbers[0], &numbers[100]);
        std::cout << "Shortest span (range of numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (range of numbers): " << sp.longestSpan() << std::endl;
    } 
	catch (std::exception &e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 6. Big test: Add 1 million numbers
    try 
	{
        Span sp(1000000);
        for (int i = 0; i < 1000000; ++i) {
            sp.addNumber(i * 3);
        }

        std::cout << "Shortest span (1 million numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (1 million numbers): " << sp.longestSpan() << std::endl;
    } 
	catch (std::exception &e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 7. Edge case: Span with only 2 numbers
    try 
	{
        Span sp(2);
        sp.addNumber(100);
        sp.addNumber(200);
        std::cout << "Shortest span (2 numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (2 numbers): " << sp.longestSpan() << std::endl;
    } 
	catch (std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}



// int main(void)
// {
//     try
//     {
//         Span sp(5);
        
//         int nUmbers[] = {6, 3, 17, 9, 11, 9};
//         sp.addNumbers(nUmbers, nUmbers + 6);
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch (std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     return (0);
// }

// int main()
// {
//     try
//     {
//         Span sp = Span(5);
   
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch (std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     return 0;
// }