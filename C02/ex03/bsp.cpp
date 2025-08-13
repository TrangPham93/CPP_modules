/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:01:21 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 13:59:12 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* shoes lace formula for area of a triangle :
	Area A = [ x1(y2 - y3) + x2(y3 - y1) + x3(y1-y2)]/2*/
static Fixed	ft_area(Point const v1, Point const v2, Point const v3)
{
	Fixed	area;
	
	area = (v1.get_x()*(v2.get_y() - v3.get_y())) 
		+ (v2.get_x()*(v3.get_y() - v1.get_y()))
		+ (v3.get_x()*(v1.get_y() - v2.get_y()));
	if (area < 0)
		area = area * Fixed(-1);
	area = area / 2;
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area1 = ft_area(a, b, point);
	Fixed	area2 = ft_area(a, c, point);
	Fixed	area3 = ft_area(b, c, point);
	Fixed	area = ft_area(a, b, c);
	
	// on the edge of the triangle or vertices
	if (area1 == 0 || area2 == 0 || area3 == 0) 
		return (false);
	else if (area1 + area2 + area3 == area)
		return (true);
	return (false);
}