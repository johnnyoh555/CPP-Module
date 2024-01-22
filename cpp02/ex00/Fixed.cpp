#include "Fixed.hpp"

void	Fixed::setRawBits(int const raw) {
	fixed_point = raw;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl; 
	return fixed_point;
}

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point = fixed.getRawBits();
}

Fixed &Fixed::operator= (const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return *this;
}