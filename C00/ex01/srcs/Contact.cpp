/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:34:24 by trpham            #+#    #+#             */
/*   Updated: 2025/08/06 16:42:43 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

std::string	Contact::get_first_name(void)
{
	return ( _firstName);
}

std::string	Contact::get_last_name(void)
{
	return ( _lastName );
}
std::string	Contact::get_nickname(void)
{
	return ( _nickName );
}
std::string	Contact::get_phone_number(void)
{
	return ( _phoneNumber );
}
std::string	Contact::get_secret(void)
{
	return ( _secret );
}

void	Contact::set_first_name(std::string firstName)
{
	_firstName = firstName;
}

void	Contact::set_last_name(std::string lastName)
{
	_lastName = lastName;
}

void	Contact::set_nickname(std::string nickname)
{
	_nickName = nickname;
}

void	Contact::set_phonenumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::set_secret(std::string secret)
{
	_secret = secret;
}

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
	Contact		NewContact;
	int			phone_book_index;
	std::string	input;
	
	std::cout << "First name : ";
	std::cin >> input;
	if (std::cin.eof())
		return;
	NewContact.set_first_name(input);
	
	std::cout << "Last name : ";
	std::cin >> input;
	if (std::cin.eof())
		return;
	NewContact.set_last_name(input);
	
	std::cout << "Nickname : ";
	std::cin >> input;
	if (std::cin.eof())
		return;
	NewContact.set_nickname(input);
	
	std::cout << "Phone number (10 digits) : ";
	std::cin >> input;
	if (std::cin.eof())
		return;
	while (!validate_phone_number(input))
	{
		std::cout << "Incorect phone number, please input again : ";
		std::cin >> input;
		if (std::cin.eof())
			return;
	}
	NewContact.set_phonenumber(input);
	
	std::cout << "Darkest secret : ";
	std::cin >> input;
	if (std::cin.eof())
		return;
	NewContact.set_secret(input);
	
	phone_book_index = index % 8;
	ContactList[phone_book_index] = NewContact;
	std::cout << "New contact is added at index " << phone_book_index + 1 << std::endl;
	PhoneBook::index++;
	return ;
}
