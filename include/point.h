#ifndef POINT_H
#define POINT_H

#include "include/vector.h"
#include "include/drawobject.h"

#include <iostream>
#include <vector>

class Point : public DrawObject {
public:
	Point();
	Point(float x, float y, float z);
	Point(float x, float y, float z, unsigned char r, unsigned char g, unsigned char b);

	void Draw(Renderer *render);

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

	unsigned char r;
	unsigned char g;
	unsigned char b;
};

#endif // POINT_H
