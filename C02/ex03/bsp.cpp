/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:01:21 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 12:33:08 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	ft_area(Point const v1, Point const v2, Point const v3)
{
	Fixed	area;
	
	// area = (v1.get_x().toFloat()*(v2.get_y().toFloat() - v3.get_y().toFloat())) 
	// 	+ (v2.get_x().toFloat()*(v3.get_y().toFloat() - v1.get_y().toFloat()))
	// 	+ (v3.get_x().toFloat()*(v1.get_y().toFloat() - v2.get_y().toFloat()));
	// area = std::abs(area) / 2;
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
	
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	else if (area1 + area2 + area3 == area)
		return (true);
	return (false);
}