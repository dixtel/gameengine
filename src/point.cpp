#include "include/point.h"

Point::Point() {

	x = y = z = 0;
}

Point::Point(float x, float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::Draw(Renderer *render) {

	render->SetPoint(x, y);
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

void Point::operator = (Point p) {

	x = p.x;
	y = p.y;
	z = p.z;
}
