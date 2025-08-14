/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:58 by trpham            #+#    #+#             */
/*   Updated: 2025/08/14 16:13:41 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("clap");
	ScavTrap	scT("scav");

	try
	{
		clap.setAttackDamage(2);
		std::cout << clap.getName() << " has " << clap.getHitPoint() 
			<< " hit points, "
			<< clap.getEnergyPoint() << " energy points and attack damage is "
			<< clap.getAttackDamage() << std::endl;
		std::cout << scT.getName() << " has " << scT.getHitPoint() 
			<< " hit points, "
			<< scT.getEnergyPoint() << " energy points and attack damage is "
			<< scT.getAttackDamage() << std::endl;
		std::cout << "\n------------battle--------------\n" << std::endl;	
		scT.attack(clap.getName());
		clap.takeDamage(scT.getAttackDamage());
		clap.attack(scT.getName());
		scT.takeDamage(clap.getAttackDamage());
		scT.guardGate();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << '\n';
		return (1);
	}
	std::cout << scT.getName() << " has " << scT.getHitPoint() 
		<< " hit points, "
		<< scT.getEnergyPoint() << " energy points" << std::endl;

	return (0);
}