#include "Point.hpp"

#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 3);
	Point point(2, 3);

	if (bsp(a, b, c, point) == true)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	return 0;
}