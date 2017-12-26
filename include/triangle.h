#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "include/point.h"
#include "include/linesegment.h"
#include "include/drawobject.h"

#include <vector>

class Triangle : public DrawObject {
public:
	Triangle(Point p1, Point p2, Point p3);

	void Draw(Renderer *render);

	std::vector <Point> GetTrianglePoints();

	Point p1;
	Point p2;
	Point p3;
};

#endif // TRIANGLE_H
