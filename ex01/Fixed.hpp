/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:37:39 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/03 19:32:44 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:

		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		Fixed 	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int	_value;
		static const int fractional = 8;
		
};

	std::ostream	&operator<<(std::ostream &os, Fixed &fixed);

#endif