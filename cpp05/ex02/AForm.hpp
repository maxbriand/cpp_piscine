/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:15:21 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/16 22:30:56 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		const std::string	_target;
		bool				_is_signed;
		const int			_signature_grade;
		const int			_execution_grade;
	public:
							AForm();
		virtual				~AForm();
							AForm(const AForm& src);
		AForm&				operator=(const AForm& src);
	public:
							AForm(const std::string name, const std::string target, const int s_grade, const int e_grade);
		std::string			getName() const;
		bool				getIsSigned() const;
		int					getSignatureGrade() const;
		int					getSignatureExecution() const;
		virtual void		execute(const Bureaucrat& executor) const = 0;
		virtual void		beSigned(const Bureaucrat& b) = 0;
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
		class NotSignedException : public std::exception {};
};

std::ostream& operator<<(std::ostream& o, const AForm& src);

#endif
