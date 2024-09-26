/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:52:43 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 16:26:44 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "colors.hpp"

Base*	generate(void)
{
	int		i;
	Base*	letter;

	std::srand(std::time(0));
	i = std::rand() % 3;
	if (i == 0)
	{
		std::cout << "A object selected!" << CLR << std::endl;
		letter = dynamic_cast<Base *> (new A());
	}
	if (i == 1)
	{
		std::cout << "B object selected!" << CLR << std::endl;
		letter = dynamic_cast<Base *> (new B());
	}
	if (i == 2)
	{
		std::cout << "C object selected!" << CLR << std::endl;
		letter = dynamic_cast<Base *> (new C());
	}
	return (letter);
}

void	identify(Base* p)
{
	A* r = dynamic_cast<A*>(p);
	if (r != 0)
	{
		std::cout << "The actual type of the object pointed by p is A!" << std::endl;
		return ;		
	}
	B* e = dynamic_cast<B*>(p);
	if (e != 0)
	{
		std::cout << "The actual type of the object pointed by p is B!" << std::endl;
		return ;		
	}
	std::cout << "The actual type of the object pointed by p is C!" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A r = dynamic_cast<A&>(p);
		std::cout << "The actual type of the object pointed by p is A!" << std::endl;
		return ;
	}
	catch (std::exception& e){}
	try
	{
		B r = dynamic_cast<B&>(p);
		std::cout << "The actual type of the object pointed by p is B!" << std::endl;
		return ;
	}
	catch (std::exception& e){}
	std::cout << "The actual type of the object pointed by p is C!" << std::endl;
}

int	main(void)
{
	Base* random_letter = generate();

	identify(random_letter);
	identify(*random_letter);
	return (0);
}
