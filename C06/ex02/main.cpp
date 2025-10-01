/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:02:08 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 22:38:03 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	// Get a different random number each time the program runs
	srand(time(0));
	
	std::cout << "\n--------test-1---------\n" << std::endl;
	Base * newBase = generate();
	identify(newBase);
	identify(*newBase);

	Base* nullBase = nullptr;
	identify(nullBase);
	
	delete newBase;

	std::cout << "\n--------test-2---------\n" << std::endl;

	Base	unknow;
	A		a;
	B		b;
	identify(unknow);
	identify(a);
	identify(b);
	
	std::cout << "\n--------test-3---------\n" << std::endl;

	Base&	refObj = a;
	identify(refObj);
		
	return 0;
}