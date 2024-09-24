/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:04 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 22:39:42 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
								RobotomyRequestForm();
								~RobotomyRequestForm();
								RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
	public:
								RobotomyRequestForm(const std::string& target);
		void					beSigned(const Bureaucrat& b);
		void					execute(const Bureaucrat& executor) const;
};

#endif