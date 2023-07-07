/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:01:30 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/07 01:35:27 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return (0);
}

// int	main(void)
// {
// 	Fixed const b( Fixed( 5.05f ) - Fixed( 2 ) );
// 	Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
// 	Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );

// 	Fixed a;

// 	std::cout << b << std::endl;
// 	std::cout << c << std::endl;
// 	std::cout << d << std::endl;
//  	std::cout << --a << std::endl;
//  	std::cout << a-- << std::endl;	
//  	std::cout << a << std::endl;

// 	std::cout << Fixed::min( b, c ) << std::endl;		
// }