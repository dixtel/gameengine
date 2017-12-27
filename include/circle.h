#ifndef CIRCLE_H
#define CIRCLE_H

#include "include/drawobject.h"
#include "include/point.h"

#include <vector>

class Circle : public DrawObject {
public:
	Circle(Point position, float radius, unsigned char r, unsigned char g, unsigned char b);

	void Draw(Renderer *render);

	std::vector <Point> GetPointsInBorderCircle();

	Point position;
	float radius;

	unsigned char r;
	unsigned char g;
	unsigned char b;
};

#endif // CIRCLE_H
