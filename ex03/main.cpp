/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:01:30 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/07 16:16:47 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float	triangle_area(Point const a, Point const b, Point const c)
{
	float area = std::abs((a.getX().toFloat()*(b.getY().toFloat() - c.getY().toFloat()) 
		+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) 
		+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2);
	
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	total_area = triangle_area(a, b, c);
	float	abp_area = triangle_area(a, b, point);
	float	bcp_area = triangle_area(b, c, point);
	float	acp_area = triangle_area(a, c, point);

	if (total_area != (abp_area + bcp_area + acp_area) 
		|| (abp_area == 0 || bcp_area == 0 || acp_area == 0))
		return (false);
	return (true);
}

int main(void)
{
	Point A(0.0, 0.0);
	Point B(5.0, 10.0);
	Point C(10.0, 0.0);
	
	Point P(5.0, 5.0);
	// Point P(5.0, 10.0);
	// Point P(-2.2, -1);
	// Point P(124134.2, 8584.32);
	
	if (bsp(A, B, C, P))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;
}