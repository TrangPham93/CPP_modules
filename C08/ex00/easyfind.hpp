/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:59:19 by trpham            #+#    #+#             */
/*   Updated: 2025/10/08 11:17:53 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

/* STL containers are divided into the following categories:
   1. Sequence Containers: implement linear data structures in which the elements can be accessed sequentially: array, vector, deque, list, forward list.
   2. Associative Containers: store data in some sorted order: set, map, multiset, multimaps.
   3. Unordered Containers: implement unsorted hashed data structures that can be quickly searched: unordered set, unordered map, unordered multiset, unordered multimap
   4. Container Adapters: provide a different interface for other containers. They adapt the behavior of underlying containers to fit specific use cases. 
   
   --> An iterator in C++ is a pointer-like object that points to an element of the STL container. They are generally used to loop through the contents of the STL container in C++. The main advantage of STL iterators is that they make the STL algorithms independent of the type of container used. We can just pass the iterator to the container elements instead of the container itself to the STL algorithms 
   
   // typename T::iterator it = std::find(t.begin(), t.end(), num); */
template <typename T>
typename T::iterator easyfind(T& t, int num)
{
   auto it = std::find(t.begin(), t.end(), num);
	if (it != t.end())
		return (it);
	throw std::runtime_error("There is no occurence of the number " + std::to_string(num));
}