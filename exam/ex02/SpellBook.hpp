#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
	private:
		ASpell*		_spellBook[100];

	public:
		SpellBook();
		SpellBook(const SpellBook& other) = delete;
		SpellBook& operator= (const SpellBook& other) = delete;
		~SpellBook();
		
		void		learnSpell(const ASpell* spell);
		void		forgetSpell(const std::string spellName);
		ASpell*		createSpell(const std::string spellName, const ATarget& target);
};

#endif