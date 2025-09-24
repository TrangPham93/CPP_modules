#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <vector>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string	_effects;

	public:
		ASpell() = delete;
		virtual ~ASpell();
		ASpell(const ASpell& other);
		ASpell& operator= (const ASpell& other);
		ASpell(std::string name, std::string effects);
		
		std::string getName() const;
		std::string	getEffects() const;
		virtual ASpell* clone() const = 0;
		void	launch(const ATarget&);
};

#endif