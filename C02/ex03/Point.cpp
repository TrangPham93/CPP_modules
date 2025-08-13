/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:01:29 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 12:23:20 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point(void): _x{0}, _y{0}
{
}

Point::~Point()
{
}

Point::Point(const float f1, const float f2): _x{Fixed(f1)}, _y{Fixed(f2)}
{
}

Point::Point(const Point& other): _x{other._x}, _y{other._y}
{
}

Fixed const	Point::get_x(void) const
{
	return _x;
}
Fixed const	Point::get_y(void) const
{
	return _y;
}


