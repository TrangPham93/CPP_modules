/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:18:46 by trpham            #+#    #+#             */
/*   Updated: 2025/08/09 20:24:59 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		newHarl;
	std::string	cmd;
	
	if (ac != 2)
	{
		std::cout << "Usage: ./harl <debug / info / warning / error>"
			<< std::endl;
		return (EXIT_FAILURE);
	}
	
	cmd = std::string(av[1]);
	for (unsigned int i = 0; i < cmd.length(); i++)
		cmd[i] = std::toupper(cmd[i]);
	if (cmd != "DEBUG" && cmd != "INFO" && cmd != "WARNING" && cmd != "ERROR")
	{
		std::cout << "Usage: only 4 values <debug / info / warning / error>" 
			<< std::endl;
		return (EXIT_FAILURE);
	}
	
	switch (Level)
	{
	case DEBUG:
		newHarl.complain("DEBUG");
	case INFO:
		newHarl.complain("INFO");
	case WARNING:
		newHarl.complain("WARNING");
	case ERROR:
		newHarl.complain("ERROR");
		break;
	}
	
	return (EXIT_SUCCESS);
}