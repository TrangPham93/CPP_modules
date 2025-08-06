/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:23:29 by trpham            #+#    #+#             */
/*   Updated: 2025/08/06 20:00:45 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string		input;
	
	std::cout << "Please type: \n ADD to add a new contact \n SEARCH to search an existing contact \n EXIT to exit the program." << std::endl;
	while (1)
	{
		std::cout << "How could I help ? ADD, SEARCH OR EXIT : ";
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cout << "\nEOF reached. Exiting." << std::endl;
			break;
		}
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchContact();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Invalid input!" << std::endl;
		if (std::cin.eof())
		{
			std::cout << "\nEOF reached. Exiting." << std::endl;
			break;
		}
	}
	return (0);
}