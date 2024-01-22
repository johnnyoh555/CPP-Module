#include "Point.hpp"

Point::Point() {}

Point::~Point() {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point &ref) : x(ref.getx()), y(ref.gety()) {}

Point &Point::operator= (const Point &ref) {ref.getx(); return *this;}

Fixed	Point::getx(void) const {return x;}

Fixed	Point::gety(void) const {return y;}