#ifndef POINT_H
#define POINT_H

#include "include/vector.h"

#include <iostream>

class Point {
public:
	Point();
	Point(float x, float y, float z);

	Point operator + (Vector v);
	Point operator - (Vector v);
	Vector operator - (Point p);
	void operator = (Point p);

	friend std::ostream &operator << (std::ostream &stream, const Point &p) {

		stream << "(" << p.x << ", " << p.y << ", " << p.z << ")";
		return stream;
	}

	float x;
	float y;
	float z;
};

#endif // POINT_H
