#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Fireball: public ASpell
{

	public:
		Fireball();
		~Fireball();
		Fireball(const Fireball& other);
		Fireball& operator= (const Fireball& other);
		
		Fireball* clone() const;
};

#endif