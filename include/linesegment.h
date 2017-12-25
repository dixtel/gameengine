#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "include/point.h"
#include "include/drawobject.h"

#include <vector>
#include <math.h>

class LineSegment : public DrawObject {
public:
	LineSegment(Point start, Point end);

	void Draw(Renderer *renderer);

	std::vector <Point> GetLineSegmentPoints();

	Point start;
	Point end;
};

#endif // LINESEGMENT_H
