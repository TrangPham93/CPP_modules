/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:18:46 by trpham            #+#    #+#             */
/*   Updated: 2025/08/09 15:08:43 by trpham           ###   ########.fr       */
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
	newHarl.complain(cmd);
	return (EXIT_SUCCESS);
}