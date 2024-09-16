/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:40:52 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/16 13:36:10 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main (void)
{
	ICharacter*	p1 = new Character("James");
	
	std::cout << std::endl << std::endl << "Cure Default Construction: "<< std::endl << std::endl;

	Cure*	c1 = new Cure();
	std::cout << "Except: 'cure'" << std::endl;
	std::cout << "Return: '" << c1->getType() << "'" << std::endl;
	std::cout << "Except: * heals James's wounds *" << std::endl << "Return: ";
	c1->use(*p1);
	delete c1;

	std::cout << std::endl << "Cure Copy construction:"<< std::endl << std::endl;
	Cure*	c2 = new Cure();
	Cure*	c3 = new Cure(*c2);
	std::cout << "Except: 'cure'" << std::endl;
	std::cout << "Return: '" << c3->getType() << "'" << std::endl;
	std::cout << "Except: * heals James's wounds *" << std::endl << "Return: ";
	c3->use(*p1);
	delete c2;
	delete c3;

	std::cout << std::endl << "Cure Overload Assignment operator:"<< std::endl << std::endl;
	Cure*	c4 = new Cure();
	Cure*	c5 = new Cure();
	*c5 = *c4;
	std::cout << "Except: 'cure'" << std::endl;
	std::cout << "Return: '" << c5->getType() << "'" << std::endl;
	std::cout << "Except: * heals James's wounds *" << std::endl << "Return: ";
	c5->use(*p1);
	delete c4;
	delete c5;

	std::cout << std::endl << "Cure clone function:"<< std::endl << std::endl;
	Cure* 		c6 = new Cure();
	AMateria* 	c7 = c6->clone();
	std::cout << "Except: 'cure'" << std::endl;
	std::cout << "Return: '" << c7->getType() << "'" << std::endl;
	std::cout << "Except: * heals James's wounds *" << std::endl << "Return: ";
	c7->use(*p1);
	delete c6;
	delete c7;

	std::cout << std::endl << std::endl << "Ice Default Construction: "<< std::endl << std::endl;

	Ice* 	i1 = new Ice();
	std::cout << "Except: 'ice'" << std::endl;
	std::cout << "Return: '" << i1->getType() << "'" << std::endl;
	std::cout << "Except: * shoots an ice bolt at James *" << std::endl << "Return: ";
	i1->use(*p1);
	delete i1;

	std::cout << std::endl << "Ice Copy construction:"<< std::endl << std::endl;
	Ice*	i2 = new Ice();
	Ice*	i3 = new Ice(*i2);
	std::cout << "Except: 'ice'" << std::endl;
	std::cout << "Return: '" << i3->getType() << "'" << std::endl;
	std::cout << "Except: * shoots an ice bolt at James *" << std::endl << "Return: ";
	i3->use(*p1);
	delete i2;
	delete i3;

	std::cout << std::endl << "Ice Overload Assignment operator:"<< std::endl << std::endl;
	Ice*	i4 = new Ice();
	Ice*	i5 = new Ice();
	*i5 = *i4;
	std::cout << "Except: 'ice'" << std::endl;
	std::cout << "Return: '" << i5->getType() << "'" << std::endl;
	std::cout << "Except: * shoots an ice bolt at James *" << std::endl << "Return: ";
	i5->use(*p1);
	delete i4;
	delete i5;

	std::cout << std::endl << "Ice clone function:"<< std::endl << std::endl;
	Ice* 		i6 = new Ice();
	AMateria* 	i7 = i6->clone();
	std::cout << "Except: 'ice'" << std::endl;
	std::cout << "Return: '" << i7->getType() << "'" << std::endl;
	std::cout << "Except: * shoots an ice bolt at James *" << std::endl << "Return: ";
	i7->use(*p1);
	delete i6;
	delete i7;

	delete p1;

	std::cout << std::endl << std::endl << "Character Default Constructer: "<< std::endl << std::endl;

	ICharacter*	p2 = new Character();
	std::cout << "Except: 'default_name'" << std::endl;
	std::cout << "Return: '" << p2->getName() << "'" << std::endl;
	std::cout << "Except: empty inventory at this index" << std::endl << "Return: ";
	p2->use(0, *p2);
	delete p2;

	std::cout << std::endl << std::endl << "Character Parametized Constructer: "<< std::endl << std::endl;

	ICharacter*	p3 = new Character("Karen");
	std::cout << "Except: 'Karen'" << std::endl;
	std::cout << "Return: '" << p3->getName() << "'" << std::endl;
	std::cout << "Except: empty inventory at this index" << std::endl << "Return: ";
	p3->use(0, *p3);

	std::cout << std::endl << std::endl << "Test equip function (+ max): "<< std::endl << std::endl;

	AMateria*	m1 = new Cure();
	AMateria*	m2 = new Ice();
	p3->equip(m1);
	p3->equip(m2);
	p3->equip(new Ice());
	p3->equip(m2);
	p3->equip(m2);
	p3->equip(m2);
	p3->unequip(3);


	std::cout << std::endl << std::endl << "Test use function on equipment: "<< std::endl << std::endl;
	std::cout << "Except: * heals Karen's wounds *" << std::endl << "Return: ";
	p3->use(0, *p3);
	std::cout << "Except: * shoots an ice bolt at Karen *" << std::endl << "Return: ";
	p3->use(1, *p3);

	delete p3;

	std::cout << std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << std::endl << "Unexcepted usecase"<< std::endl << std::endl;
	IMateriaSource* ms1 = new MateriaSource();
	AMateria* c1000 = new Cure();
	ms1->learnMateria(c1000);
	delete ms1;

	ICharacter* p18 = new Character("Ethan");	
	p18->equip(new Cure());
	p18->equip(NULL);
	p18->unequip(0);
	p18->unequip(10);
	p18->equip(new Cure());
	p18->use(0, *p18);
	p18->use(1, *p18);
	p18->use(-1, *p18);
	IMateriaSource *jekd = new MateriaSource();
	jekd->learnMateria(NULL);
	jekd->learnMateria(new Cure());
	jekd->createMateria("fje");
	p18->equip(jekd->createMateria("cure"));
	delete jekd;

	Cure *newoneone = new Cure();
	Cure *nsk = new Cure(*newoneone);
	nsk->use(*p18);
	delete newoneone; delete nsk;
	delete p18;
	return (0);
}
