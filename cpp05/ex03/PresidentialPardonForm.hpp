/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:07 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 16:29:09 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
								PresidentialPardonForm();
								~PresidentialPardonForm();
								PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
	public:
								PresidentialPardonForm(const std::string& target);
		void					beSigned(const Bureaucrat& b);
		void					execute(const Bureaucrat& executor) const;
};

#endif