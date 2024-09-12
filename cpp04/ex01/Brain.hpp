/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:23:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 16:50:09 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
						Brain(void);
						Brain(const Brain& src);
						~Brain(void);
		Brain& 			operator=(const Brain& src);
		// std::string*	getIdeas(void) const;
		// void			setIdeas(int i, std::string value);

	private:
		std::string _ideas[100];
};

#endif
