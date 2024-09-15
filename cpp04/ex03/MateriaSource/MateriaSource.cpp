/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:07:25 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 21:53:00 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_learn_list[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		if (_learn_list[i])
			delete _learn_list[i];
		i++;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &src)
{
	int	i;

	if (this == &src)
		return (*this);
	i = 0;
	while (i < 4)
	{
		if (!src._learn_list[i])
		{
			_learn_list[i] = NULL;
		}
		else
		{
			*_learn_list[i] = *src._learn_list[i];
		}
		i++;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* src)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!_learn_list[i])
		{
			_learn_list[i] = src->clone();
			break ;
		}
		i++;
	}
	delete src;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i;
	AMateria*	new_materia;

	i = 0;
	new_materia = NULL;
	while (i < 4)
	{
		if (_learn_list[i] && _learn_list[i]->getType() == type)
		{
			new_materia = _learn_list[i]->clone();
			break ;
		}
		i++;
	}
	return (new_materia);
}

