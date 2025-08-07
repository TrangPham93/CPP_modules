/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:31:06 by trpham            #+#    #+#             */
/*   Updated: 2025/08/07 17:53:26 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie*	zombieHorde = nullptr;
	
	if (N <= 0 || N > 100000)
	{
		std::cout << "Error: Invalid N, must be in range (0, 1000]" << std::endl;
		return (nullptr);
	}
	try
	{
		zombieHorde = new Zombie[N];
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (nullptr);
	}
	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].set_name(name);
	}
	return (zombieHorde);
}