/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:20:06 by trpham            #+#    #+#             */
/*   Updated: 2025/08/07 17:56:19 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*		newHorde;
	int			N;
	std::string	name;

	N = 100000;
	name = "JUMBO";

	newHorde = zombieHorde(N, name);
	if (!newHorde)
		return (1);
	
	for (int i = 0; i < N; i++)
	{
		newHorde[i].announce();
	}
	
	delete[]	newHorde;
	newHorde = nullptr;

	return (0);
}