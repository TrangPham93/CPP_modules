/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:49:34 by trpham            #+#    #+#             */
/*   Updated: 2025/09/26 15:54:51 by trpham           ###   ########.fr       */
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
		ShrubberyCreationForm newForm("home");
		Bureaucrat	Jim("Jim", 150);
		std::cout << newForm << std::endl;
		
		newForm.beSigned(Jim);
		std::cout << newForm << std::endl;
		
		newForm.execute(Jim);
		
		Bureaucrat	Cal("Cal", 13);
		Cal.signForm(newForm);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	std::cout << "\n----------test-robotomy---------\n" << std::endl;
	try
	{
		RobotomyRequestForm  newForm("factory");
		Bureaucrat	Kate("Kate", 50);
		std::cout << newForm << std::endl;
		
		Kate.signForm(newForm);
		std::cout << newForm << std::endl;
		Kate.executeForm(newForm);
		newForm.execute(Kate);
		
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	std::cout << "\n----------test-president---------\n" << std::endl;
	try
	{
		PresidentialPardonForm newForm("kkk");
		Bureaucrat	Mill("Mill", 6);
		Bureaucrat	Kate("Kate", 3);
		std::cout << newForm << std::endl;
		
		newForm.beSigned(Mill);
		std::cout << newForm << std::endl;

		newForm.execute(Kate);
		Kate.signForm(newForm);
			
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
	return 0;
}