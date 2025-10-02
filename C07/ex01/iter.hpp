/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:50:36 by trpham            #+#    #+#             */
/*   Updated: 2025/10/02 21:26:30 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


/* 	function pointer:
	f is a pointer to a function that: takes a parameter of type T& and 
	returns void. 
	void iter(T* arr, unsigned int len, void (*f)(T&)) -> 
	F can be a function pointer, lambda, or function template instantiated.
	No need to match exact function pointer type — the compiler deduces it. */
template <typename T, typename F>
void iter(T* arr, unsigned int len, F f)
{
	for (unsigned int i = 0; i < len; i++)
		f(arr[i]); // equal to (*f)(arr[i]) 
}