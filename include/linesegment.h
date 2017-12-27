#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "include/point.h"
#include "include/drawobject.h"

#include <vector>
#include <math.h>

class LineSegment : public DrawObject {
public:
	LineSegment(Point start, Point end, unsigned char r, unsigned char g, unsigned char b);

	void Draw(Renderer *render);

	std::vector <Point> GetLineSegmentPoints();

	Point start;
	Point end;

	unsigned char r;
	unsigned char g;
	unsigned char b;
};

#endif // LINESEGMENT_H
