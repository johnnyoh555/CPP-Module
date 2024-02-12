#include "Fixed.hpp"

void	Fixed::setRawBits(int const raw) {
	fixed_point = raw;
}

int	Fixed::getRawBits(void) const {
	return fixed_point;
}

Fixed::Fixed() {
	fixed_point = 0;
}

Fixed::Fixed(const int num) {
	this->fixed_point = num << fractional_bits;
}

Fixed::Fixed(const float num) {
	this->fixed_point = roundf(num * (1 << fractional_bits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed) {
	this->fixed_point = fixed.getRawBits();
}

Fixed &Fixed::operator= (const Fixed &fixed) {
	setRawBits(fixed.getRawBits());
	return *this;
}

int	Fixed::toInt(void) const {
	return ((fixed_point >> fractional_bits));
}

float Fixed::toFloat(void) const {
	return ((float)fixed_point / (1 << fractional_bits));
}

bool	Fixed::operator> (const Fixed &fixed) const {
	return this->fixed_point > fixed.fixed_point;
}

bool	Fixed::operator< (const Fixed &fixed) const {
	return this->fixed_point < fixed.fixed_point;
}

bool	Fixed::operator>= (const Fixed &fixed) const {
	return this->fixed_point >= fixed.fixed_point;
}

bool	Fixed::operator<= (const Fixed &fixed) const {
	return this->fixed_point <= fixed.fixed_point;
}

bool	Fixed::operator== (const Fixed &fixed) const {
	return this->fixed_point == fixed.fixed_point;
}

bool	Fixed::operator!= (const Fixed &fixed) const {
	return this->fixed_point != fixed.fixed_point;
}

Fixed Fixed::operator+ (const Fixed &fixed) const {
	Fixed ret(this->toFloat() + fixed.toFloat());
	return ret;
}

Fixed Fixed::operator- (const Fixed &fixed) const {
	Fixed ret(this->toFloat() - fixed.toFloat());
	return ret;
}

Fixed Fixed::operator* (const Fixed &fixed) const {
	Fixed ret(this->toFloat() * fixed.toFloat());
	return ret;
}

Fixed Fixed::operator/ (const Fixed &fixed) const {
	Fixed ret(this->toFloat() / fixed.toFloat());
	return ret;
}

Fixed	&Fixed::operator++ () {
	fixed_point += 1;
	return *this;
}

const Fixed	Fixed::operator++ (int) {
	const Fixed	tmp(toFloat());

	++(*this);
	return tmp;
}

Fixed	&Fixed::operator-- () {
	fixed_point -= 1;
	return *this;
}

const Fixed	Fixed::operator-- (int) {
	const Fixed	tmp(toFloat());

	--(*this);
	return tmp;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return b;
	return a;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return b;
	return a;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}
