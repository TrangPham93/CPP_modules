/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:31:04 by trpham            #+#    #+#             */
/*   Updated: 2025/08/01 13:36:56 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Megaphone.hpp"

void	Megaphone::Capitalize(std::string &MyString)
{
	if (!MyString.empty())
	{
		for (unsigned int i = 0; i < MyString.length(); i++)
		{
			if (MyString[i] >= 97 && MyString[i] <= 122)
				MyString[i] -= 32;
		};
		
	}
}

int	main(int ac, char **av)
{
	Megaphone	MyObj;
		
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
		MyObj.MyString += av[i];
	MyObj.Capitalize(MyObj.MyString);
	std::cout << MyObj.MyString << std::endl;
	return 0;
}