/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:18:10 by trpham            #+#    #+#             */
/*   Updated: 2025/09/15 19:33:53 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() 
	: _formName("unknown"), _isSign(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form: constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form: destructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) :_formName(name),
	_isSign(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form: para_constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other): _formName(other._formName), 
	_isSign(other._signGrade), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Form: copy constructor called" << std::endl;
	if (other._signGrade < 1 || other._executeGrade < 1)
		throw Form::GradeTooLowException();
	else if (other._signGrade > 150 || other._executeGrade > 150)
		throw Form::GradeTooHighException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSign = other._isSign;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Exception: Form's grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Exception: Form's grade is too low";
}

	
void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < 1)
		throw Form::GradeTooHighException();
	else if (b.getGrade() > 150)
		throw Form::GradeTooLowException();
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSign = true;	
}

std::string Form::getFormName() const
{
	return _formName;
}

bool	Form::getSignStatus() const
{
	return _isSign;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int			Form::getExecuteGrade() const
{
	return _executeGrade;	
}

std::ostream& operator << (std::ostream& out, Form& obj)
{
	out << "Form " << obj.getFormName() << ", has sign grade of " 
		<< obj.getSignGrade() << " and execute grade of " 
		<< obj.getExecuteGrade() ;
	if (obj.getSignStatus() == true)
		out << " -> is signed";
	else
		out << " -> is not signed";
	return out;
}
