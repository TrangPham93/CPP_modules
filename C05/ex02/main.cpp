/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:49:34 by trpham            #+#    #+#             */
/*   Updated: 2025/09/18 16:52:07 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* the object method throws exception, so the object goes out of scope in 
try block, resulting in destructor called. 
After that, catch block print the message, so exception is printed after 
destructor */
int	main()
{
	std::cout << "\n----------test-shrubbery---------\n" << std::endl;
	try
	{
		AForm*		newForm = new ShrubberyCreationForm("home");
		Bureaucrat	Jim("Jim", 12);
		std::cout << *newForm << std::endl;
		
		newForm->beSigned(Jim);
		std::cout << *newForm << std::endl;
		
		newForm->execute(Jim);
		
		Bureaucrat	Cal("Cal", 13);
		Cal.signForm(*newForm);
		Cal.executeForm(*newForm);
		delete newForm;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	std::cout << "\n----------test-robotomy---------\n" << std::endl;
	try
	{
		AForm*		newForm = new RobotomyRequestForm("factory");
		Bureaucrat	Bill("Bill", 46);
		Bureaucrat	Kate("Kate", 3);
		
		std::cout << newForm->getFormName() << ": sign grade of " 
			<< newForm->getSignGrade() << ", execute grade of " 
			<< newForm->getExecuteGrade() << ", signed == " 
			<< newForm->getSignStatus() << std::endl;
		newForm->beSigned(Bill);
		newForm->execute(Bill);
		Kate.executeForm(*newForm);
		
		delete newForm;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	std::cout << "\n----------test-president---------\n" << std::endl;
	try
	{
		AForm*		newForm = new PresidentialPardonForm("blue house");
		Bureaucrat	Mill("Mill", 6);
		Bureaucrat	Kate("Kate", 3);
		
		std::cout << newForm->getFormName() << ": sign grade of " 
			<< newForm->getSignGrade() << ", execute grade of " 
			<< newForm->getExecuteGrade() << ", signed == " 
			<< newForm->getSignStatus() << std::endl;
		newForm->beSigned(Mill);
		newForm->execute(Mill);
		newForm->execute(Kate);
			
		delete newForm;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}


	return 0;
}