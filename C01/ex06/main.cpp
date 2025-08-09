/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:18:46 by trpham            #+#    #+#             */
/*   Updated: 2025/08/09 21:35:43 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static Level	string_to_enum(std::string s)
{
	if (s == "DEBUG")
		return DEBUG;
	if (s == "INFO")
		return INFO;
	if (s == "WARNING")
		return WARNING;
	return ERROR;
}

static void	print_level(std::string cmd)
{
	Harl		newHarl;
	
	switch (string_to_enum(cmd))
	{
		case DEBUG:
			std::cout << "[ " << "DEBUG" << " ]" << std::endl;
			newHarl.complain("DEBUG");
			std::cout << std::endl;
			[[fallthrough]];
		case INFO:
			std::cout << "[ " << "INFO" << " ]" << std::endl;
			newHarl.complain("INFO");
			std::cout << std::endl;
			[[fallthrough]];
		case WARNING:
			std::cout << "[ " << "WARNING" << " ]" << std::endl;
			newHarl.complain("WARNING");
			std::cout << std::endl;
			[[fallthrough]];
		case ERROR:
			std::cout << "[ " << "ERROR" << " ]" << std::endl;
			newHarl.complain("ERROR");
			break;
	}
}

int	main(int ac, char **av)
{
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
	
	print_level(cmd);
	return (EXIT_SUCCESS);
}
