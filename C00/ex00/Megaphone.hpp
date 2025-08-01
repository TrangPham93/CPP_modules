/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:30:41 by trpham            #+#    #+#             */
/*   Updated: 2025/08/01 13:36:04 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <iostream>

class	Megaphone{
	public:
		// Attribute
		std::string MyString;

		// Constructor
		Megaphone(){
			MyString = "";
		};
		
		// Method
		void		Capitalize(std::string &MyString);

		// Destructor
		~Megaphone(){};
};

#endif