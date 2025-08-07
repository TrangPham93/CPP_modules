/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:20:06 by trpham            #+#    #+#             */
/*   Updated: 2025/08/07 16:26:46 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	heapZombie = newZombie("heapZombie");
	if (heapZombie)
	{
		std::cout << "Zombie on heap: " << heapZombie->get_name() << std::endl;
		heapZombie->announce();
		delete	heapZombie;
	}
	
	std::cout << "Zombie on stack: stackZombie" << std::endl;
	randomChump("stackZombie");
	
	return (0);
}