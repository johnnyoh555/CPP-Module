#include "Fixed.hpp"

#include <iostream>

int main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(Fixed(-1.5f));
	
	std::cout << c.toInt() << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << a + b << std::endl;
	std::cout << b + a << std::endl;
	std::cout << b / a << std::endl;
	std::cout << b * a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}