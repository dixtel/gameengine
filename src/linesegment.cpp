#include "include/linesegment.h"

LineSegment::LineSegment(Point start, Point end, unsigned char r, unsigned char g, unsigned char b) {

	this->start = start;
	this->end = end;
	this->r = r;
	this->g = g;
	this->b = b;
}

void LineSegment::Draw(Renderer *render) {

	std::vector <Point> points = GetLineSegmentPoints();

	for (int i = 0; i < points.size(); ++i) {

		render->SetDrawColor(SDL_Color{r, g, b, 255});
		render->SetPoint(points[i].x, points[i].y);
	}
}

std::vector <Point> LineSegment::GetLineSegmentPoints() {

	std::vector <Point> points;
	Point p1 = start;
	Point p2 = end;

	if (p1.x == p2.x) {

		int y;
		int max;

		if (p1.y > p2.y) {

			y = p2.y;
			max = p1.y;
		}
		else {

			y = p1.y;
			max = p2.y;
		}

		for (int i = y; i < max; ++i) {

			points.push_back(Point(p1.x, i, 0, r, g, b));
		}

		return points;
	}

	if (p1.y == p2.y) {

		int x;
		int max;

		if (p1.x > p2.x) {

			x = p2.x;
			max = p1.x;
		}
		else {

			x = p1.x;
			max = p2.x;
		}

		for (int i = x; i < max; ++i) {

			points.push_back(Point(i, p1.y, 0, r, g, b));
		}

		return points;
	}

	if (p1.y < p2.y)
		std::swap(p1, p2);

	Point direction(p2.x - p1.x, p2.y - p1.y, 0);
	float slope = abs(direction.y / direction.x);

	// for increments x by step
	if (slope <= 1) {

		int step = (p1.x < p2.x) ? 1 : -1;
		float curr_error = 0;

		int x = p1.x;
		int y = p1.y;

		do {

			points.push_back(Point(x, y, 0, r, g, b));
			curr_error += slope;

			while (curr_error >= 0.5) {

				y += (direction.y > 0) - (direction.y < 0);
				curr_error -= 1;
			}

			x += step;
		} while (x != p2.x);
	}
	else { 	// for increments y by step

		slope = abs(direction.x / direction.y);
		int step = 1;
		float curr_error = 0;

		int x = p1.x;
		int y = p1.y;

		do {

			points.push_back(Point(x, y, 0, r, g, b));
			curr_error += slope;

			while (curr_error >= 0.5) {

				x += (direction.x > 0) - (direction.x < 0);
				curr_error -= 1;
			}

			y -= step;
		} while (y != p2.y);
	}
	return points;
}
