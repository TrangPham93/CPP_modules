/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:01:26 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 13:59:27 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;
	
public:
	Point(void);
	~Point();
	Point(const float f1, const float f2);
	Point(const Point& other);
	// @note: once the const variable is initialized, it cannot be reassigned, so delete the operator=
	Point& operator = (const Point& other) = delete; 

	Fixed const	get_x(void) const;
	Fixed const	get_y(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
