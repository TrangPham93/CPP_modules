/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:05:35 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 18:23:32 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdint>

struct Data;

/* uintptr_t is unsigned int type, that is designed to store a pointer. It's 
guaranteed to be large enough to hold any memory address on the system it's 
compiled on.  */
class Serializer
{
private:
	
public:
	Serializer() = delete;
	~Serializer();
	Serializer(const Serializer& other) = delete;
	Serializer& operator= (const Serializer& other) = delete;

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

