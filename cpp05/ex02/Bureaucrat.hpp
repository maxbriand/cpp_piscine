/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:45:12 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 16:03:45 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "iostream"
#include "string"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;
	public:
							Bureaucrat();
							~Bureaucrat();
							Bureaucrat(const Bureaucrat& src);
		Bureaucrat&			operator=(const Bureaucrat& src);
	public:
							Bureaucrat(const std::string name, const int grade);
		std::string			getName() const;
		int					getGrade() const;
		void				Promotion();
		void				Punition();
		void				signForm(const AForm& form) const;
		void				executeForm(const AForm& form);
		class GradeTooHighException : public std::exception{};
		class GradeTooLowException : public std::exception{};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& src);

#endif