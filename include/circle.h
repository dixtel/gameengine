#ifndef CIRCLE_H
#define CIRCLE_H

#include "include/drawobject.h"
#include "include/point.h"

#include <vector>

class Circle : public DrawObject {
public:
	Circle(Point position, float radius);

	void Draw(Renderer *render);

	std::vector <Point> GetPointsInBorderCircle();

	Point position;
	float radius;
};

#endif // CIRCLE_H
