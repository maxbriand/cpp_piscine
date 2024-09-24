/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:02 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 15:32:35 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATEFORM_HPP
# define SHRUBBERYCREATEFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
								ShrubberyCreationForm();
								~ShrubberyCreationForm();
								ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
	public:
								ShrubberyCreationForm(const std::string& target);
		void					beSigned(const Bureaucrat& b);
		void					execute(const Bureaucrat& executor) const;
};

#endif