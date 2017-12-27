#ifndef POLYGON_H
#define POLYGON_H

#include "include/point.h"
#include "include/linesegment.h"
#include "include/drawobject.h"

#include <vector>

class Polygon : public DrawObject {
public:
	Polygon(std::vector <Point> points, unsigned char r, unsigned char g, unsigned char b);

	void Draw(Renderer *render);

	void SetPoints(std::vector <Point> points);
	void SetPoint(unsigned id, Point point);

	std::vector <Point> GetPolygonPoints();

	std::vector <Point> points;

	unsigned char r;
	unsigned char g;
	unsigned char b;
};

#endif // POLYGON_H
