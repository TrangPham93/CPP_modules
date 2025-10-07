/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:28:48 by trpham            #+#    #+#             */
/*   Updated: 2025/10/07 11:44:58 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <stack>


/* Stack container follows LIFO (Last In First Out) order of insertion and 
deletion. It means that most recently inserted element is removed first and the
 first inserted element will be removed last. This is done by inserting and 
 deleting elements at only one end of the stack which is generally called the 
 top of the stack .
std::stack is an adapter, not a container. It uses another container (by 
default std::deque<T>) internally, called c (protected member)*/
template <typename T>
class MutantStack: public std::stack<T>
{
private:
	
public:
	MutantStack() = default;
	~MutantStack() = default;
	MutantStack(const MutantStack& other) = default;
	MutantStack& operator= (const MutantStack& other) = default;

	using iterator = typename std::stack<T>::container_type::iterator;
	iterator begin()	{ return this->c.begin(); };
	iterator end()		{ return this->c.end(); };

	using const_iterator = typename std::stack<T>::container_type::const_iterator;
	const_iterator begin() const	{ return this->c.begin(); };
	const_iterator end() const		{ return this->c.end(); };

	using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
	reverse_iterator rbegin()	{ return this->c.rbegin(); };
	reverse_iterator rend()		{ return this->c.rend(); };

	using const_reverse_iterator 	 = typename std::stack<T>::container_type::const_reverse_iterator 	;
	const_reverse_iterator 	 rbegin() const	{ return this->c.rbegin(); };
	const_reverse_iterator 	 rend() const	{ return this->c.rend(); };
	
};



