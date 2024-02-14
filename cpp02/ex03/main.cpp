#include "Point.hpp"

#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point a(5, 5);
	Point b(-3, 3);
	Point c(3, -3);
	Point point(-2.08, 1.84);

	if (bsp(a, b, c, point) == true)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	return 0;
}