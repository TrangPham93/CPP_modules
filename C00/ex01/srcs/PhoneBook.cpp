/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:52:43 by trpham            #+#    #+#             */
/*   Updated: 2025/08/06 16:42:21 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
}

PhoneBook::~PhoneBook(void){}

static std::string truncate_to_ten(std::string str)
{	
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + ".");
}

static void display_phonebook(Contact *ContactList, int index)
{
	int	phonebook_end;
	
	if (index < 8)
		phonebook_end = index;
	else
		phonebook_end = 8;
	std::cout << std::right << std::setw(10) << "Index" << "|"
		<< std:: right << std::setw(10) << "First name" << "|"
		<< std:: right << std::setw(10) << "Last name" << "|" 
		<< std:: right << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < phonebook_end; i++)
		std::cout << std::right << std::setw(10) << i + 1 << "|" 
		<< std::right << std::setw(10) << truncate_to_ten(ContactList[i].get_first_name()) << "|" 
		<< std::right << std::setw(10) << truncate_to_ten(ContactList[i].get_last_name()) << "|"
		<< std::right << std::setw(10) << truncate_to_ten(ContactList[i].get_first_name()) << std::endl;
}

static void	display_contact(Contact *ContactList, int search_index)
{
	std::cout << std::left << std::setw(15) << "First name" << ":"
		<< ContactList[search_index].get_first_name() << std::endl;
	std::cout << std::left << std::setw(15) << "Last name" << ":"
		<< ContactList[search_index].get_last_name() << std::endl;
	std::cout << std::left << std::setw(15) << "Nickname" << ":" 
		<< ContactList[search_index].get_nickname() << std::endl;
	std::cout << std::left << std::setw(15) << "Phone number" << ":" 
		<< ContactList[search_index].get_phone_number() << std::endl;
	std::cout << std::left << std::setw(15) << "Dark secret" << ":" 
		<< ContactList[search_index].get_secret() << std::endl;
}

static bool	validate_index(std::string search_string)
{
	if (search_string.length() != 1)
	{
		std::cout << "ERROR: Number in range 1 and 8 included" <<std::endl;
		return (false);
	}
	if (search_string[0] < '1' || search_string[0] > '8')
	{
		std::cout << "ERROR: Must be a valid number" <<std::endl;
		return (false);
	}
	return (true);
}

void	PhoneBook::SearchContact()
{
	std::string	search_str;
	int			search_index;
	
	display_phonebook(ContactList, PhoneBook::index);
	while (1)
	{
		std::cout << "See contact details (number between 1 - 8) : ";
		std::cin >> search_str;
		if (std::cin.eof())
			return;
		if (validate_index(search_str))
			break ;
	}
	search_index = search_str[0] - '0';
	if (search_index - 1 >= index)
	{
		std::cout << "No contact saved at this index yet\n";
		return ;
	}
	display_contact(ContactList, search_index - 1);
}
