/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:37:39 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/30 16:54:47 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();

		Fixed 	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int	_value;
		static const int fractional = 8;
		
};

#endif