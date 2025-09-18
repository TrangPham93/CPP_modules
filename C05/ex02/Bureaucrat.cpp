/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:23:56 by trpham            #+#    #+#             */
/*   Updated: 2025/09/18 12:21:40 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
	std::cout << "Bureaucrat: constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int newGrade): _name(name)
{
	std::cout << "Bureaucrat: para_constructor called" << std::endl;
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
	_grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Bureaucrat: copy constructor called" << std::endl;
	if (other._grade < 1)
		throw GradeTooHighException();
	else if (other._grade > 150)
		throw GradeTooLowException();
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat: copy assignment called" << std::endl;
	if (this == &other)
		return (*this);
	if (other._grade < 1)
		throw GradeTooHighException();
	else if (other._grade > 150)
		throw GradeTooLowException();
	_grade = other._grade;
	return (*this);
}

std::string		Bureaucrat::getName() const
{
	return _name;	
}

unsigned int		Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	std::cout << "try to increment" << std::endl;
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;	
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "try to decrement" << std::endl;
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: Grade is too low";
}

std::ostream& operator << (std::ostream &out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return out;
}

void	Bureaucrat::signForm(AForm& formToSign)
{
	try
	{
		formToSign.beSigned(*this);
		std::cout << this->getName() << " signed " 
			<< formToSign.getFormName()
			<< std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " 
			<< formToSign.getFormName() << " because "
			<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (form.getSignStatus() == true)
		throw	AForm::FormAlreadySigned();
	if (this->getGrade() > form.getExecuteGrade())
		throw	Bureaucrat::GradeTooLowException();
	std::cout << this->getGrade() << " executed " << form.getFormName();
}