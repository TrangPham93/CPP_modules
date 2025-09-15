/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:49:34 by trpham            #+#    #+#             */
/*   Updated: 2025/09/15 17:16:18 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* the object method throws exception, so the object goes out of scope in 
try block, resulting in destructor called. 
After that, catch block print the message, so exception is printed after 
destructor */
int	main()
{
	std::cout << "\n----------test-1---------\n" << std::endl;
	try
	{
		Bureaucrat	Jim("Jim", 2);
		
		std::cout << Jim << std::endl;
		Jim.incrementGrade();		
		std::cout << Jim << std::endl;
		Jim.incrementGrade();
		std::cout << Jim << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
	
	std::cout << "\n----------test-2---------\n" << std::endl;
	try
	{
		Bureaucrat	Min;
		
		std::cout << Min << std::endl;
		Min.decrementGrade();		
		std::cout << Min << std::endl;
		Min.decrementGrade();
		std::cout << Min << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	std::cout << "\n----------test-3---------\n" << std::endl;
	try
	{
		Bureaucrat	Bill("Bill", 176);
		
		std::cout << Bill << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	std::cout << "\n----------test-4---------\n" << std::endl;
	try
	{
		Bureaucrat	Bill("Bill", 150);
		Bureaucrat	Kat("Kat", 15);
		
		std::cout << Kat << std::endl;
		Kat = Bill;
		std::cout << Kat << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
	
	return 0;
}