/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:57:11 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 14:16:37 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

#define INPUT_ERR "Error: input RPN inside \"\" and mathematical operator +-*/ only"
#define DIV_0_ERR "Error: cannot divide by 0"
#define OTHER_ERR "Error"

/* stack: access in order of LIFO */
class RPN
{
private:
	std::stack<double>	_fl;
	
public:
	RPN() = default;
	~RPN() = default;
	RPN(const RPN& other) = default;
	RPN& operator= (const RPN& other) = default;
	
	size_t	size();
	void	addNumber(int num);
	void	printFL();
	void	calculate(char op);
};


