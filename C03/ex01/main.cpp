/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:58 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 22:22:44 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	// ClapTrap	clA("clA");
	ScavTrap	scT("newscap");

	try
	{
		// clA.setAttackDamage(5);
		// std::cout << clA.getName() << " has " << clA.getHitPoint() 
		// 	<<  " hit points, "	<< clA.getEnergyPoint() 
		// 	<< " energy points and attack damage is "
		// 	<< clA.getAttackDamage() << std::endl;
		std::cout << scT.getName() << " has " << scT.getHitPoint() 
			<< " hit points, "
			<< scT.getEnergyPoint() << " energy points and attack damage is "
			<< scT.getAttackDamage() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << '\n';
		return (1);
	}
	// std::cout << clA.getName() << " has " << clA.getHitPoint() 
	// 	<<  " hit points, "	<< clA.getEnergyPoint() 
	// 	<< " energy points " << std::endl;
	// std::cout << scT.getName() << " has " << scT.getHitPoint() 
	// 	<< " hit points, "
	// 	<< scT.getEnergyPoint() << " energy points" << std::endl;

	return (0);
}