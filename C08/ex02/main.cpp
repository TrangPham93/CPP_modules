/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:28:20 by trpham            #+#    #+#             */
/*   Updated: 2025/10/07 14:04:23 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "\n---------subject-test---------\n\n";

	try
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "last value of stack: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size of stack after removing last value: " 
			<< mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "all values in Mutant stack: "	<< std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);
		std::cout << "all values in stack adapter (bottom to top): " 
			<< std::endl;

		while (!s.empty())
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	
	try
	{
		
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
		
		std::cout << "after capitalizing all elements: " << std::endl;
		for (it = charStack.begin(); it != charStack.end(); ++it)
			*it = std::toupper(*it);
		for (it = charStack.begin(); it != charStack.end(); ++it)
			std::cout << *it << ".";
		std::cout << std::endl;
		
		std::cout << "\n----------const-iterator--------\n\n";
		
		const MutantStack<char> charStackConst(charStack);
		std::cout << "size of charStackconst: " << charStackConst.size() << std::endl;

		MutantStack<char>::const_iterator conit;
		for (conit = charStackConst.begin(); conit != charStackConst.end(); ++conit)
			std::cout << *conit << ".";
		std::cout << std::endl;
		
		std::cout << "\n----------reverse-iterator--------\n\n";

		MutantStack<char> reverseStack(charStack);
		MutantStack<char>::reverse_iterator reit;

		for (reit = reverseStack.rbegin(); reit != reverseStack.rend(); ++reit)
			std::cout << *reit << ".";
		std::cout << std::endl;
		while (!reverseStack.empty())
			reverseStack.pop();
		std::cout << "size of reverseStack after removing elements: " 
			<< reverseStack.size() << std::endl;
		
		std::cout << "\n---------const-reverse-iterator--------\n\n";

		const MutantStack<char> revConStack(charStack);
		MutantStack<char>::const_reverse_iterator reconit;

		for (reconit = revConStack.rbegin(); reconit != revConStack.rend(); 
			++reconit)
			std::cout << *reconit << ".";
		std::cout << std::endl;
		std::cout << "size of const reverse stack: " << revConStack.size() 
			<< std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n---------compare-mutant-with-list-------\n\n";
	try
	{
		MutantStack<std::string> stringStack;
		stringStack.push("Hello");
		stringStack.push("new");
		stringStack.push("world");
		stringStack.push("***");

		std::list<std::string> stringList;
		stringList.push_back("Hello");
		stringList.push_back("new");
		stringList.push_back("world");
		stringList.push_back("***");

		stringStack.pop();
		stringList.pop_back();
		
		std::cout << "member of mutant stack: " << std::endl;
		for (auto it = stringStack.begin(); it != stringStack.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "member of list: " << std::endl;
		for (auto it = stringList.begin(); it != stringList.end(); ++it)
			std::cout << *it << std::endl;


	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
	return 0;
}