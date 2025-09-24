#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		ATarget*		_targetBook[100];

	public:
		TargetGenerator();
		TargetGenerator(const TargetGenerator& other) = delete;
		TargetGenerator& operator= (const TargetGenerator& other) = delete;
		~TargetGenerator();
		
		void		learnTargetType(ATarget* target);
		void		forgetTargetType(std::string const& targetType);
		ATarget*	createTarget(std::string const& targetType);
};

#endif