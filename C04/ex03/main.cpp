/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:44:24 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 16:25:03 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"	

int main()
{
	std::cout << "\n----------------test-default----------\n" <<std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter*		me = new Character("me");
	AMateria*		tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter*		bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	std::cout << "\n----------------test-1----------\n" <<std::endl;
	AMateria*	nonMateria;
	Ice			ice1;
	
	nonMateria = &ice1;
	std::cout << "nonMateria's type: " << nonMateria->getType() << std::endl;
	
	std::cout << "\n----------------test-2----------\n" <<std::endl;
	AMateria*	validIce = new Ice();
	AMateria*	validCure = new Cure();
	ICharacter*	staff1 = new Character("staff_1");
	ICharacter* staff2 = new Character("staff_2");
	
	staff1->equip(validIce);
	staff1->equip(validIce);
	staff1->equip(validCure);
	staff1->equip(validCure);
	staff1->equip(validCure);
	staff1->use(1, *staff2);

	AMateria*	tempIdx = static_cast<Character*>(staff1)->getInvMateria(1);
	
	staff1->unequip(1);
	staff1->use(1, *staff2);
	delete	validIce;
	delete	validCure;
	delete	staff1;
	delete	staff2;
	delete	tempIdx;
	
	return 0;
}