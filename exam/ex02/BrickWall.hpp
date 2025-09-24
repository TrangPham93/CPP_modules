#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class BrickWall: public ATarget 
{
	public:
		BrickWall();
		~BrickWall();
		BrickWall(const BrickWall& other);
		BrickWall& operator= (const BrickWall& other);
		
		BrickWall* clone() const;
};

#endif