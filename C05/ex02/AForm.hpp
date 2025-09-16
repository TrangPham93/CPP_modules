/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:18:04 by trpham            #+#    #+#             */
/*   Updated: 2025/09/16 13:23:00 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_formName;
	bool				_isSign;
	const int			_signGrade;
	const int			_executeGrade;

public:
	AForm();
	virtual ~AForm();
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	std::string getFormName() const;
	bool		getSignStatus() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;

	virtual void	beSigned(Bureaucrat& b) = 0;
};

std::ostream& operator << (std::ostream& out, AForm& obj);


