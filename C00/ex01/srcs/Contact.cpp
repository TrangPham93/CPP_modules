/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:34:24 by trpham            #+#    #+#             */
/*   Updated: 2025/08/02 14:17:44 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.hpp"

Contact::~Contact(){
	FirstName = "";
	LastName = "";
	NickName = "";
	PhoneNumber = "";
	Secret = "";
}

bool	validate_phone_number(std::string PhoneNumber)
{
	if (PhoneNumber.length() != 10)
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (!isdigit(PhoneNumber[i]))
			return (false);
	}
	return (true);
}

void	add_phonebook()
{
	
	std::cout << "New contact is added!\n";
}

void	PhoneBook::AddContact(void)
{
	Contact	NewContact;
	
	std::cout << "First name : ";
	std::cin >>	NewContact.FirstName;
	std::cout << "Last name : ";
	std::cin >>	NewContact.LastName;
	std::cout << "Nickname : ";
	std::cin >>	NewContact.NickName;
	std::cout << "Phone number (10 digits) : ";
	std::cin >>	NewContact.PhoneNumber;
	while (!validate_phone_number(NewContact.PhoneNumber))
	{
		std::cout << "Incorect phone number, please input again : ";
		std::cin >>	NewContact.PhoneNumber;
	}
	std::cout << "Darkest secret : ";
	std::cin >>	NewContact.Secret;
	add_phonebook();
	return ;
}



// void	PhoneBook::SearchContact(unsigned int index)
// {

// }

