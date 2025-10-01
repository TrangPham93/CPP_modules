/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:05:35 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 15:34:23 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdint>

struct Data;

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

