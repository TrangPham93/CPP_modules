/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:27:07 by trpham            #+#    #+#             */
/*   Updated: 2025/08/07 16:27:23 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// can use throw std::bad_alloc() to test try catch block
Zombie*	newZombie( std::string name )
{
	Zombie* heapZombie;

	heapZombie = nullptr;
	try
	{
		heapZombie = new (Zombie);
	}
	catch(const std::exception& e)
	{
		std::cout << "create heapZombie failed: "<<  e.what() << std::endl;
		return (nullptr);
	}
	heapZombie->set_name(name);	
	return (heapZombie);
}