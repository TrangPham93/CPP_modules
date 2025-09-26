/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:18:04 by trpham            #+#    #+#             */
/*   Updated: 2025/09/26 12:29:58 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_formName;
	bool				_isSign;
	const unsigned int	_signGrade;
	const unsigned int	_executeGrade;

public:
	Form() = delete;
	~Form();
	Form(std::string name, unsigned int signGrade, unsigned int executeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class FormAlreadySigned : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	std::string 	getFormName() const;
	bool			getSignStatus() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecuteGrade() const;

	void		beSigned(Bureaucrat& b);
};

std::ostream& operator << (std::ostream& out, Form& obj);


