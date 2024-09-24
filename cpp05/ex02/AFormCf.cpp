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

AForm::AForm() : _name("Default_form"), _target("Default_target"), \
			_is_signed(0), _signature_grade(1), _execution_grade(2){}

AForm::~AForm(){}

AForm::AForm(const AForm& src) : _name(src._name), _target(src._target), \
			_signature_grade(src._signature_grade), _execution_grade(src._execution_grade)
{
	*this = src;
}

AForm&	AForm::operator=(const AForm& src)
{
	this->_is_signed = src._is_signed;
	return (*this);
}
