/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:23:29 by trpham            #+#    #+#             */
/*   Updated: 2025/08/04 18:44:06 by trpham           ###   ########.fr       */
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
		
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchContact();
		else if (input == "EXIT")
			exit(EXIT_SUCCESS);
		else
			std::cout << "Invalid input! \n";
	}
	return 0;
}