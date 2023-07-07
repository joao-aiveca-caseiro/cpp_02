/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:30:22 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/06 16:16:08 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_value = fixed.getRawBits();
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = num << fractional;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = (roundf(num * (1 << this->fractional)));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;		
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	this->_value = ((long)(this->_value + (long)fixed._value));
	//return (Fixed(this->toFloat() + fixed.toFloat()));
	return (*this);
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	this->_value = ((this->_value - fixed._value));
	//return (Fixed(this->toFloat() - fixed.toFloat()));
	return (*this);
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	this->_value = (((long long)this->_value * (long long)fixed._value) >> fixed.fractional);
	//return(Fixed(this->toFloat() * fixed.toFloat()));
	return (*this);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	this->_value = ((((long long)this->_value << fixed.fractional) / fixed._value));
	//return (Fixed(this->toFloat() / fixed.toFloat()));
	return (*this);
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

Fixed	&Fixed::max(Fixed &fixedA, Fixed &fixedB)
{
	return (fixedA._value > fixedB._value ? fixedA : fixedB);
}

const Fixed	&Fixed::max(const Fixed &fixedA, const Fixed &fixedB)
{
	return (fixedA._value > fixedB._value ? fixedA : fixedB);
}

Fixed	&Fixed::min(Fixed &fixedA, Fixed &fixedB)
{
	return (fixedA._value < fixedB._value ? fixedA : fixedB);	
}

const Fixed	&Fixed::min(const Fixed &fixedA, const Fixed &fixedB)
{
	return (fixedA._value < fixedB._value ? fixedA : fixedB);	
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}