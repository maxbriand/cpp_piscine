/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:53:22 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/11 16:48:24 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

class Cure
{
	public:
					Cure(void);
					~Cure(void);
					Cure(const Cure& src);
		Cure& 		operator=(const Cure& src);

	public:
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
