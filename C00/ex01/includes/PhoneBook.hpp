/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:44:02 by trpham            #+#    #+#             */
/*   Updated: 2025/08/06 19:55:31 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstring>
# include <iomanip>
# include "Contact.hpp"

# define MAX 8

class	PhoneBook {
	private:
		Contact	_ContactList[MAX];
		int		_index;
		
	public:
		// Constructor
		PhoneBook(void);
		
		// Method
		void	AddContact(void);
		void	SearchContact(void);
		
		// Destructor
		~PhoneBook(void);
};

#endif