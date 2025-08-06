/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:31:04 by trpham            #+#    #+#             */
/*   Updated: 2025/08/06 17:08:53 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(int ac, char **av)
{
	std::string	myString;
	
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
	for (int i = 1; i < ac; i++)
		myString += av[i];
	for (unsigned int index = 0; index < myString.length(); index++)
		std::cout << char(std::toupper(myString[index]));
	std::cout << std::endl;
	
	return 0;
}