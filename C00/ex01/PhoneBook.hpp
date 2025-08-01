/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:44:02 by trpham            #+#    #+#             */
/*   Updated: 2025/08/01 16:50:24 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook {
	public:
		// Attributes
		Contact	ContactList[8];

		// Method
		void	AddContact(void);
		void	SearchContact(unsigned int index);
		
};

#endif