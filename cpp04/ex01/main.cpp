/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:18:45 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 21:49:29 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Brain *brain1 = new Brain();
	Brain *brain_cpy = new Brain(*brain1);
	std::cout << std::endl;
	delete brain1;
	delete brain_cpy; 
	std::cout << std::endl;

	Dog	*dog1 = new Dog();
	Dog	*dog_cpy = new Dog(*dog1);
	std::cout << std::endl;
	std::cout << "Type of dog1 is: " << dog1->getType() << std::endl;
	std::cout << "Type of dog_cpy is: " << dog_cpy->getType() << std::endl;
	std::cout << std::endl;
	delete dog1;
	delete dog_cpy;
	std::cout << std::endl;

	const Animal* an1 = new Cat();
	delete an1;//should not create a leak
	std::cout << std::endl;

	Animal	*farm[2];
	int				i;

	i = 0;
	while (i < 2)
	{
		if (i % 2)
			farm[i] = new Dog();
		else
			farm[i] = new Cat();
		i++;		
	}
	farm[0]->makeSound();
	farm[1]->makeSound();
	i--;
	while (i >= 0)
	{
		delete farm[i];
		i--;
	}

	std::cout << std::endl;

	Dog ann;
	Dog ann2;

	ann = ann2;

	std::cout << std::endl;


}
