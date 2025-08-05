/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:34:24 by trpham            #+#    #+#             */
/*   Updated: 2025/08/05 17:10:06 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Contact::Contact(){
	FirstName = "";
	LastName = "";
	NickName = "";
	PhoneNumber = "";
	Secret = "";
}

Contact::~Contact(){}

static bool	validate_phone_number(std::string PhoneNumber)
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

void	PhoneBook::AddContact(void)
{
	Contact	NewContact;
	int		phone_book_index;
	
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
	phone_book_index = index % 8;
	ContactList[phone_book_index] = NewContact;
	std::cout << "New contact is added at index " << phone_book_index + 1 << std::endl;
	PhoneBook::index++;
	return ;
}
