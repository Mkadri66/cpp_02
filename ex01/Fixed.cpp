/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:50:10 by mkadri            #+#    #+#             */
/*   Updated: 2024/10/29 11:02:02 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int const Fixed::_bits = 8;


Fixed::Fixed(): _n(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	_n = n << _bits;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	_n = roundf(f * (1 << _bits));
}

Fixed::Fixed(Fixed const & fCpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this=fCpy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


int	Fixed::getRawBits() const {
	return this->_n;
}

void	Fixed::setRawBits(int const raw) {
	this->_n = raw;
}


float	Fixed::toFloat() const {
	return static_cast<float>(_n) / 256;
}

int	Fixed::toInt() const {
	return _n / 256;
}


Fixed&	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = rhs.getRawBits();

	return *this;
}

std::ostream &	operator<<(std::ostream & opStream, Fixed const & rhs) {

	opStream << rhs.toFloat();
	return opStream;
}