/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:28:20 by trpham            #+#    #+#             */
/*   Updated: 2025/10/07 12:14:49 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	// std::cout << "\n---------subject-test---------\n\n";
	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);
	
	std::cout << "\n----------iterator--------\n\n";
	
	MutantStack<char> charStack;
	charStack.push('h');
	charStack.push('E');
	charStack.push('l');
	charStack.push('l');
	charStack.push('O');
	charStack.push('!');
	std::cout << "size of charStack: " << charStack.size() << std::endl;

	MutantStack<char>::iterator it;
	for (it = charStack.begin(); it != charStack.end(); ++it)
		std::cout << *it << ".";
	std::cout << std::endl;
	
	for (it = charStack.begin(); it != charStack.end(); ++it)
		*it = std::toupper(*it);
	for (it = charStack.begin(); it != charStack.end(); ++it)
		std::cout << *it << ".";
	std::cout << std::endl;
	
	std::cout << "\n----------const-iterator--------\n\n";
	
	const MutantStack<char> charStackConst;
	std::cout << "size of charStackconst: " << charStackConst.size() << std::endl;

	MutantStack<char>::const_iterator conit;
	for (conit = charStackConst.begin(); conit != charStackConst.end(); ++conit)
		std::cout << *conit << ".";
	std::cout << std::endl;
	
	std::cout << "\n----------reverse-iterator--------\n\n";

	MutantStack<char> reverseStack(charStack);
	MutantStack<char>::reverse_iterator reit;

	for (reit = reverseStack.rbegin())
	while (!charStackConst.empty())
	{
		charStackConst.pop();
	}
	std::cout << "size of charStack: " << charStackConst.size() << std::endl;
	// charStack.pop();
	// charStack

		
	
	return 0;
}