/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:34:24 by trpham            #+#    #+#             */
/*   Updated: 2025/08/01 16:51:31 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.hpp"

void	PhoneBook::AddContact(void)
{
	Contact	NewContact;
	
	std::cout << "First name : ";
	std::cin >>	NewContact.FirstName;
	std::cout << "Last name : ";
	std::cin >>	NewContact.LastName;
	std::cout << "Nickname : ";
	std::cin >>	NewContact.NickName;
	std::cout << "Phone number : ";
	std::cin >>	NewContact.PhoneNumber;
	std::cout << "Darkest secret : ";
	std::cin >>	NewContact.Secret;
	std::cout << "New contact is added!\n";
	return ;
	
}

void	PhoneBook::SearchContact(unsigned int index)
{

}

