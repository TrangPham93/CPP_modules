/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:44:02 by trpham            #+#    #+#             */
/*   Updated: 2025/08/04 17:56:03 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstring>
# include <iomanip>
# include "Contact.hpp"

# define MAX 8

class	PhoneBook {
	public:
		// Constructor
		PhoneBook();

		// Attributes
		Contact	ContactList[MAX];
		int		index;
		
		// Method
		void	AddContact(void);
		void	SearchContact();
		
		// Destructor
		~PhoneBook();
};

#endif