#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string _type;

	public:
		ATarget() = delete;
		virtual ~ATarget();
		ATarget(const ATarget& other);
		ATarget& operator= (const ATarget& other);
		ATarget(std::string type);
		
		std::string getType() const;
		virtual ATarget* clone() const = 0;

		void getHitBySpell(const ASpell& target) const;
};

#endif