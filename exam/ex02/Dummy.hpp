#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Dummy: public ATarget 
{
	public:
		Dummy();
		~Dummy();
		Dummy(const Dummy& other);
		Dummy& operator= (const Dummy& other);
		
		Dummy* clone() const;
};

#endif