/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:31:04 by trpham            #+#    #+#             */
/*   Updated: 2025/08/01 16:25:03 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class	Megaphone {
	public:
		// Attribute
		std::string MyString;

		// Constructor
		Megaphone() {
			MyString = "";
		};
};

int	main(int ac, char **av)
{
	Megaphone	MyObj;
		
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
	for (int i = 1; i < ac; i++)
		MyObj.MyString += av[i];
	for (unsigned int index = 0; index < MyObj.MyString.length(); index++)
		std::cout << char(std::toupper(MyObj.MyString[index]));
	std::cout << std::endl;
	
	return 0;
}