/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:53:17 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 21:48:49 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base*	generate(void)
{
	// Generate a random number between 0 and 2
	switch (rand() % 3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	default:
		return (new C);
	}
}

/* If the object being pointed to is of the correct type (or a type convertible
 to it), the cast succeeds. If the cast is invalid, the pointer is set to 
 nullptr or it is a reference, then it throws std::bad_cast exception. */
void	identify(Base* p)
{
	if (p == nullptr)
		std::cout << "Null pointer" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Cannot identify" << std::endl;
}
	
void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;	
	}
	catch(const std::bad_cast& ){}
	 
	try
	{
		(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::bad_cast& e){}
	
	try
	{
		(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::bad_cast& e){}
	
	std::cout << "Cannot identify" << std::endl;
}