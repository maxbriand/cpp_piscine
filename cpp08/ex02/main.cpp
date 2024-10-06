/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:52:09 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/28 14:01:02 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// int main() 
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);
//     mstack.push(3);
//     mstack.push(7);
//     mstack.push(12);

//     MutantStack<int> mstack_copy(mstack);

//     MutantStack<int> mstack_assigned;
//     mstack_assigned = mstack;

//     std::cout << "Copied MutantStack (forward): ";
//     for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) 
// 	{
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Assigned MutantStack (forward): ";
//     for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it) 
// 	{
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     mstack.push(42);
//     std::cout << "Original MutantStack after modifying (forward): ";
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) 
// 	{
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Copied MutantStack after modifying original (forward): ";
//     for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	// --it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}