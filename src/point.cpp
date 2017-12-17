#include "include/point.h"

Point::Point() {

	x = y = x = 0;
}

Point::Point(float x, float y, float x) {

	this->x = x;
	this->y = y;
	this->z = z;
}

Point Point::operator + (Vector v) {

	return Point(x + v.x, y + v.y, z + v.z);
}

Point Point::operator - (Vector v) {

	return Point(x - v.x, y - v.y, z - v.z);
}

Vector Point::operator - (Point p) {

	return Vector(x - p.x, y - p.y, z - p.z);
}
