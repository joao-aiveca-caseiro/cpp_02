/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:14:27 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/07 03:51:54 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(float x, float y): _x(x), _y(y){}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY()){}

Point	&Point::operator=(const Point &point)
{
	return (*this);
}

