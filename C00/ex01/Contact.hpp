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
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	Secret;
		// Constructor
		Contact() {
			FirstName = "";
			LastName = "";
			NickName = "";
			PhoneNumber = "";
			Secret = "";
		}

		// Destructor
		~Contact();
};

#endif