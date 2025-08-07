/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:34:24 by trpham            #+#    #+#             */
/*   Updated: 2025/08/07 11:38:20 by trpham           ###   ########.fr       */
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

Contact	Contact::askInput( void )
{
	Contact		NewContact;
	std::string	input;
	
	std::cout << "First name : ";
	std::cin >> input;
	if (std::cin.eof())
		return (Contact()) ;
	NewContact.set_first_name(input);
	
	std::cout << "Last name : ";
	std::cin >> input;
	if (std::cin.eof())
		return (Contact()) ;
	NewContact.set_last_name(input);
	
	std::cout << "Nickname : ";
	std::cin >> input;
	if (std::cin.eof())
		return (Contact()) ;
	NewContact.set_nickname(input);
	
	std::cout << "Phone number (10 digits) : ";
	std::cin >> input;
	if (std::cin.eof())
		return (Contact()) ;
	while (!validate_phone_number(input))
	{
		std::cout << "Incorect phone number, please input again : ";
		std::cin >> input;
		if (std::cin.eof())
			return (Contact()) ;
	}
	NewContact.set_phonenumber(input);
	
	std::cout << "Darkest secret : ";
	std::cin >> input;
	if (std::cin.eof())
		return (Contact()) ;
	NewContact.set_secret(input);
	return (NewContact);
}

bool Contact::is_valid( void )
{
	return (!_firstName.empty() && !_lastName.empty() && !_nickName.empty()
	&& !_phoneNumber.empty() && !_secret.empty());
}

void	PhoneBook::AddContact(void)
{
	Contact		NewContact;
	int			phone_book_index;

	NewContact = NewContact.askInput();
	if (NewContact.is_valid())
	{
		phone_book_index = PhoneBook::_index % 8;
		_ContactList[phone_book_index] = NewContact;
		std::cout << "New contact is added at index " << (phone_book_index + 1) << std::endl;
		PhoneBook::_index++;
	}
	return ;
}
