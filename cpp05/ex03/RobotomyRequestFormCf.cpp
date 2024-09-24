/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormCf.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:09 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 20:10:01 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): \
	AForm("robotomy request", "Default_target", 72, 45){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): \
	AForm(src.getName(), src._target, 72, 45)
{
	*this = src;
}

RobotomyRequestForm& 	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	_is_signed = src._is_signed;
	return (*this);
}
