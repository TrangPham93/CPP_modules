/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:02:08 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 21:49:11 by trpham           ###   ########.fr       */
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
	try
	{
		Base * newBase = generate();
		identify(newBase);
		identify(*newBase);

		Base* nullBase = nullptr;
		identify(nullBase);
		
		delete newBase;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}