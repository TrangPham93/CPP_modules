/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:59:03 by trpham            #+#    #+#             */
/*   Updated: 2025/08/02 14:01:49 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact {
	public:
		// Constructor
		Contact();
		// Contact(
		// 	std::string	FirstName,
		// 	std::string	LastName,
		// 	std::string	NickName,
		// 	std::string	PhoneNumber,
		// 	std::string	Secret);
		
		// Attribute
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	Secret;

		// Destructor
		~Contact();
};

#endif