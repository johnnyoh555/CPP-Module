#include "Point.hpp"


float	triangle_size(Point const a, Point const b, Point const c) {
	Fixed	tmp;

	tmp = (b.getx() - a.getx()) * (c.gety() - a.gety()) - (b.gety() - a.gety()) * (c.getx() - a.getx());
	return tmp.toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float	main_r;
	float	first_r;
	float	second_r;
	float	third_r;

	main_r = triangle_size(a, b, c);
	if (main_r == 0)
		return false;
	if (main_r < 0)
		main_r *= -1;
	first_r = triangle_size(a, b, point);
	if (first_r == 0)
		return false;
	if (first_r < 0)
		first_r *= -1;
	second_r = triangle_size(a, c, point);
	if (second_r == 0)
		return false;
	if (second_r < 0)
		second_r *= -1;
	third_r = triangle_size(b, c, point);
	if (third_r == 0)
		return false;
	if (third_r < 0)
		third_r *= -1;
	if (main_r == first_r + second_r + third_r)
		return true;
	return false;
}