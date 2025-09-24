#include "SpellBook.hpp"

SpellBook::SpellBook()
{
	for (int i= 0; i < 100; i++)
	{
		_spellBook[i] = nullptr;
	}
}
SpellBook::~SpellBook()
{
	for (int i= 0; i < 100; i++)
	{
		delete _spellBook[i];
	}
}


void	SpellBook::learnSpell(const ASpell* spell)
{
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] != nullptr)
		{
			if (_spellBook[i]->getName() == spell->getName())
				return;
		}
	}
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] == nullptr)
		{
			_spellBook[i] = spell->clone();
			return;
		}
	}
}

void	SpellBook::forgetSpell(const std::string spellName)
{
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] != nullptr 
			&& _spellBook[i]->getName() == spellName)
		{
			delete _spellBook[i];
			_spellBook[i] = nullptr;
			return;
		}
	}
}

ASpell*	SpellBook::createSpell(const std::string spellName, const ATarget& target)
{
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] != nullptr 
			&& _spellBook[i]->getName() == spellName)
		{
			
			return _spellBook[i]->clone();
		}
	}
	return nullptr;
}