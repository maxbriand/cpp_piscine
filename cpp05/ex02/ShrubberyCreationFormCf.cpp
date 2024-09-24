/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationFormCf.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:05 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 15:03:04 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): \
	AForm("ShrubberyCreationForm", "Default_target", 145, 137){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): \
	AForm(src.getName(), src._target, 145, 137)
{
	*this = src;
}

ShrubberyCreationForm& 	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	_is_signed = src._is_signed;
	return (*this);
}
