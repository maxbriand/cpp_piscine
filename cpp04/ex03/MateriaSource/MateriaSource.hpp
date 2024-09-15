/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:07:28 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 14:04:25 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria*		_learn_list[4];
	public:
						MateriaSource();
						MateriaSource(const MateriaSource& src);
						~MateriaSource();
		MateriaSource&	operator=(const MateriaSource &src);
	public:
		void			learnMateria(AMateria* src);
		AMateria*		createMateria(std::string const & type);
};

#endif
