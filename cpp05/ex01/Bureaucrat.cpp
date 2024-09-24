/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:46:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/16 22:57:40 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default name"), _grade(150) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name)
{
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	this->_grade = src._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	try 
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException& h)
	{
		std::cout << getName() << "'s grade is too high, so Bureaucrat grade is set with max grade: 1" << std::endl;
		_grade = 1;
	}
	catch (...)
	{
		std::cout << getName() << "'s grade is too loo, so Bureaucrat grade is set with min grade: 150" << std::endl;
		_grade = 150;
	}
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade()const
{
	return (_grade);
}

void	Bureaucrat::Promotion()
{
	try
	{
		if (_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade--;
	}
	catch (...)
	{
		std::cout << "A Bureaucrat of grade 1 cannot get a promotion!" << std::endl;
	}
}

void	Bureaucrat::Punition()
{
	try
	{
		if (_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade++;
	}
	catch (...)
	{
		std::cout << "A Bureaucrat of grade 1 cannot be punished!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (o);
}

void	Bureaucrat::signForm(const Form& form) const
{
	if (form.getIsSigned() == 1)
		std::cout << *this << " signed " << form << std::endl;
	else
		std::cout << *this << " didn't signed " << form << " because grade too low" << std::endl;
}
