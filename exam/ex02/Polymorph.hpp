#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Polymorph: public ASpell
{

	public:
		Polymorph();
		~Polymorph();
		Polymorph(const Polymorph& other);
		Polymorph& operator= (const Polymorph& other);
		
		Polymorph* clone() const;
};

#endif