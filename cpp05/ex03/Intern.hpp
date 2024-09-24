/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:31 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 19:49:46 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern 
{
   public:
		AForm*	makeForm(const std::string name_form, const std::string target);

   public:
	   Intern();
	   Intern(const Intern& other);
	   Intern& operator=(const Intern& other);
	   ~Intern();
};

#endif



