/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:59:03 by trpham            #+#    #+#             */
/*   Updated: 2025/08/06 23:24:39 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact {
	public:
		// Constructor
		Contact(void);
		// Destructor
		~Contact(void);
		
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_secret(void);
		void		set_first_name(std::string firstName);
		void		set_last_name(std::string lastName);
		void		set_nickname(std::string nickname);
		void		set_phonenumber(std::string phoneNumber);
		void		set_secret(std::string secret);
		static Contact	askInput( void );
		bool		is_valid();

		
	private:
		// Attribute
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_secret;

};

#endif