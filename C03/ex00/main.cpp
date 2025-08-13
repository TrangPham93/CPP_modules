/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:58 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 17:12:32 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clA("clA");
	ClapTrap	clB;

	clB.setName("clB");

	try
	{
		clA.setAttackDamage(5);
		clB.setAttackDamage(2);
		std::cout << clA.getName() << " has " << clA.getHitPoint() 
			<<  " hit points, "	<< clA.getEnergyPoint() 
			<< " energy points and attack damage is "
			<< clA.getAttackDamage() << std::endl;
		std::cout << clB.getName() << " has " << clB.getHitPoint() 
			<< " hit points, "
			<< clB.getEnergyPoint() << " energy points and attack damage is "
			<< clB.getAttackDamage() << std::endl;

		std::cout << "------------battle--------------" << std::endl;	
		clA.attack(clB.getName());
		clB.takeDamage(clA.getAttackDamage());
		clB.attack(clA.getName());
		clA.takeDamage(2);
		clB.beRepaired(1);
		clA.attack(clB.getName());
		clB.takeDamage(clA.getAttackDamage());
		clA.beRepaired(1);
		clB.attack(clA.getName());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << '\n';
		return (1);
	}
	std::cout << clA.getName() << " has " << clA.getHitPoint() 
		<<  " hit points, "	<< clA.getEnergyPoint() 
		<< " energy points " << std::endl;
	std::cout << clB.getName() << " has " << clB.getHitPoint() 
		<< " hit points, "
		<< clB.getEnergyPoint() << " energy points" << std::endl;

	return (0);
}