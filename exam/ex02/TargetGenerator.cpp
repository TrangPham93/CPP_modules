#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
	for (int i= 0; i < 100; i++)
	{
		_targetBook[i] = nullptr;
	}
}
TargetGenerator::~TargetGenerator()
{
	for (int i= 0; i < 100; i++)
	{
		delete _targetBook[i];
	}
}


void	TargetGenerator::learnTargetType(ATarget* target)
{
	for (int i= 0; i < 100; i++)
	{
		if (_targetBook[i] != nullptr)
		{
			if (_targetBook[i]->getType() == target->getType())
				return;
		}
	}
	for (int i= 0; i < 100; i++)
	{
		if (_targetBook[i] == nullptr)
		{
			_targetBook[i] = target->clone();
			return;
		}
	}
}

void	TargetGenerator::forgetTargetType(std::string const& targetType)
{
	for (int i= 0; i < 100; i++)
	{
		if (_targetBook[i] != nullptr 
			&& _targetBook[i]->getType() == targetType)
		{
			delete _targetBook[i];
			_targetBook[i] = nullptr;
			return;
		}
	}
}

ATarget*	TargetGenerator::createTarget(std::string const& targetType)
{
	for (int i= 0; i < 100; i++)
	{
		if (_targetBook[i] != nullptr 
			&& _targetBook[i]->getType() == targetType)
		{
			return _targetBook[i]->clone();
		}
	}
	return nullptr;
}