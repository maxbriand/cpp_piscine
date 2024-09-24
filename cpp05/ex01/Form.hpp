/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:15:21 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/16 22:30:56 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_signature_grade;
		const int			_execution_grade;
	public:
							Form();
							~Form();
							Form(const Form& src);
		Form&				operator=(const Form& src);
	public:
							Form(const std::string name);
		std::string			getName() const;
		bool				getIsSigned() const;
		int					getSignatureGrade() const;
		int					getSignatureExecution() const;
		void				beSigned(const Bureaucrat& b);
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
};

std::ostream& operator<<(std::ostream& o, const Form& src);

#endif
