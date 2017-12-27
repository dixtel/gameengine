#ifndef QUAD_H
#define QUAD_H

#include "include/point.h"
#include "include/linesegment.h"
#include "include/drawobject.h"

#include <vector>

class Quad : public DrawObject {
public:
	Quad(Point p1, Point p2, Point p3, Point p4, unsigned char r, unsigned char g, unsigned char b);

	void Draw(Renderer *render);

	std::vector <Point> GetQuadPoints();

	Point p1;
	Point p2;
	Point p3;
	Point p4;

	unsigned char r;
	unsigned char g;
	unsigned char b;
};

#endif // QUAD_H
