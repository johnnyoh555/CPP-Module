#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed	x;
		const Fixed y;
		Point	&operator= (const Point &ref);
		Point();

	public:
		Point(float x, float y);
		Point(const Point &ref);
		~Point();

		Fixed	getx(void) const;
		Fixed	gety(void) const;
};

#endif