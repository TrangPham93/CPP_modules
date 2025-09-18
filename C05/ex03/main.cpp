/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:49:34 by trpham            #+#    #+#             */
/*   Updated: 2025/09/18 17:13:19 by trpham           ###   ########.fr       */
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

	return 0;
}