/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:10:43 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/06 13:27:23 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float x, float y);
		Point(const Point &point);
		~Point();

		Point 	&operator=(const Point &point);
		Fixed 	&getX(void) const;
		Fixed	&getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

	bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif