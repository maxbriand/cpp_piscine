/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:57:17 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 15:20:18 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Animal {
public:
    void sound() const {
        std::cout << "Animal sound\n";
    }
	virtual	~Animal(){}
};

class Cat : public Animal {
public:
    void sound() const 
	{
        std::cout << "Meow\n";
    }
	~Cat(){}
};

class Dog : public Animal 
{
};

int main(void)
{
	// Cat* animal = new Cat();
	Cat test;
	Animal *pt_test = &test;
	pt_test->sound();  // Calls Cat's sound() because of virtual dispatch
	std::cout << pt_test << " and " << &test << std::endl;
	
	// delete animal;
	Animal *animal2 = new Dog();
	animal2->sound();
	return (0);
}