/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:30:22 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/05 17:30:34 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = fixed.getRawBits();
	//*this = fixed;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << fractional;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (roundf(num * (1 << this->fractional)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;		
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	return(Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->_value > fixed._value);
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->_value < fixed._value);
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->_value >= fixed._value);
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->_value <= fixed._value);
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (this->_value == fixed._value);
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->_value != fixed._value);
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);	
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->fractional));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->fractional);	
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}