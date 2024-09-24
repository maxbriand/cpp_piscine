/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:15:51 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/16 23:01:13 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const std::string target, const int s_grade, const int e_grade): _name(name),\
					_target(target), _is_signed(0), _signature_grade(s_grade), _execution_grade(e_grade){}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_is_signed);
}

int	AForm::getSignatureGrade() const
{
	return (_signature_grade);
}

int	AForm::getSignatureExecution() const
{
	return (_execution_grade);
}

std::ostream& operator<<(std::ostream& o, const AForm& src)
{
	o << src.getName() << " form of signature grade: " << src.getSignatureGrade() << ", of execution grade: ";
	o << src.getSignatureExecution() << ", and of status: ";
	if (src.getIsSigned())
		o << "SIGNED";
	else
		o << "NOT SIGNED";
	return (o);
}
