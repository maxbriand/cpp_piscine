/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonFormCf.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:33:56 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 16:31:45 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): \
	AForm("PresidentialPardonForm", "Default_target", 25, 5){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): \
	AForm(src.getName(), src._target, 25, 5)
{
	*this = src;
}

PresidentialPardonForm& 	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	_is_signed = src._is_signed;
	return (*this);
}
