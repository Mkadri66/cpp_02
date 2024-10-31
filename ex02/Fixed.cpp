/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:50:10 by mkadri            #+#    #+#             */
/*   Updated: 2024/10/31 17:11:14 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int const Fixed::_bits = 8;

// constructors

Fixed::Fixed(): _n(0) {}

Fixed::Fixed(int const n) {
	_n = n << _bits;
}

Fixed::Fixed(float const f) {
	_n = roundf(f * (1 << _bits));
}

Fixed::Fixed(Fixed const & fCpy) {
	*this=fCpy;
}

Fixed::~Fixed() {}

// getters - setters

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

// operators 

Fixed&	Fixed::operator=(Fixed const & rhs) {
	this->_n = rhs.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const & rhs) const {
	Fixed result;
	result.setRawBits(this->_n + rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator-(Fixed const & rhs) const {
	Fixed result;
	result.setRawBits(this->_n - rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator*(Fixed const & rhs) const {
	Fixed result;
	result.setRawBits((this->_n * rhs.getRawBits()) >> _bits);
	return result;
}

Fixed	Fixed::operator/(Fixed const & rhs) const {
	Fixed result;
	result.setRawBits((this->_n << _bits) / rhs.getRawBits());
	return result;
}

// comparison

bool	Fixed::operator>(Fixed const & rhs) const {
	return this->_n > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const & rhs) const {
	return this->_n < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	return this->_n >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	return this->_n <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs) const {
	return this->_n == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	return this->_n != rhs.getRawBits();
}

//  increment / decrement

Fixed&	Fixed::operator++() {
	this->_n += 1;
	return *this;
}


Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	this->_n += 1;
	return temp;
}


Fixed&	Fixed::operator--() {
	this->_n -= 1;
	return *this;
}


Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	this->_n -= 1;
	return temp;
}

//

Fixed&   Fixed::min(Fixed& a, Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed&   Fixed::max(Fixed& a, Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

//

std::ostream&	operator<<(std::ostream & opStream, Fixed const & rhs) {

	opStream << rhs.toFloat();
	return opStream;
}