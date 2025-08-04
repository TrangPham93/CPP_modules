/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:52:43 by trpham            #+#    #+#             */
/*   Updated: 2025/08/04 18:52:03 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = -1;
}

PhoneBook::~PhoneBook(){}

static void	display_contact(Contact *ContactList, int search_index)
{
	std::cout << std::right << std::setw(10) << "Index" << "|"
		<< std:: right << std::setw(10) << "First name" << "|"
		<< std:: right << std::setw(10) << "Last name" << "|" 
		<< std:: right << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::right << std::setw(10) << search_index << "|" 
		<< std::right << std::setw(10) << ContactList[search_index].FirstName << "|" 
		<< std::right << std::setw(10) << ContactList[search_index].LastName << "|"
		<< std::right << std::setw(10) << ContactList[search_index].NickName << std::endl;
}

static bool	validate_index(std::string search_string)
{
	if (search_string.length() != 1)
		return (false);
	if (search_string[0] < '0' || search_string[0] > '7')
		return (false);
	return (true);
}

void	PhoneBook::SearchContact()
{
	std::string	search_str;
	int			search_index;
	
	while (1)
	{
		std::cout << "Input contact index (number between 0 - 7) : ";
		std::cin >> search_str;
		if (search_str == "EXIT")
			break;
		if (!validate_index(search_str))
		{
			std::cout << "Invalid index" << std::endl;
			continue ;
		}
		search_index = search_str[0] - '0';
		if (search_index > index)
		{
			std::cout << "No contact saved at this index yet\n";
			continue;
		}
		display_contact(ContactList, search_index);
	}
}


