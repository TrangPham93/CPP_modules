/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:44:02 by trpham            #+#    #+#             */
/*   Updated: 2025/08/02 13:58:00 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstring>
# include "Contact.hpp"

class	PhoneBook {
	public:
		// Attributes
		Contact	ContactList[8];

		// Method
		void	AddContact(void);
		// void	SearchContact(unsigned int index);
		
		// Constructor
		PhoneBook();

		// Destructor
		~PhoneBook();
};

#endif