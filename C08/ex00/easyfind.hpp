/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:59:19 by trpham            #+#    #+#             */
/*   Updated: 2025/10/06 12:34:36 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <array>

/* STL containers are divided into the following categories:
   1. Sequence Containers: implement linear data structures in which the elements can be accessed sequentially: array, vector, deque, list, forward list.
   2. Associative Containers: store data in some sorted order: set, map, multiset, multimaps.
   3. Unordered Containers: implement unsorted hashed data structures that can be quickly searched: unordered set, unordered map, unordered multiset, unordered multimap
   4. Container Adapters: provide a different interface for other containers. They adapt the behavior of underlying containers to fit specific use cases. */

template <typename T>
int easyfind(T t, int num)
{
	for (unsigned int i = 0; i < t.size(); i ++)
	{
		if (t.at(i) == num)
			return i;
	}
	throw std::runtime_error("There is no occurence of the number " + std::to_string(num));
}