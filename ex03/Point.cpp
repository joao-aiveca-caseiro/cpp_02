/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:14:27 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/07 15:31:13 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(float x, float y): _x(x), _y(y){}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY()){}

Point::~Point(){}

Point	&Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}

const Fixed &Point::getX() const
{
	return(this->_x);
}

const Fixed &Point::getY() const
{
	return(this->_y);
}
