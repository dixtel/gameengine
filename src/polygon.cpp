#include "include/polygon.h"

Polygon::Polygon(std::vector <Point> points, unsigned char r, unsigned char g, unsigned char b) {

	this->points = points;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Polygon::Draw(Renderer *render) {

	std::vector <Point> points = GetPolygonPoints();

	for (int i = 0; i < points.size(); ++i) {

		render->SetDrawColor(SDL_Color{r, g, b, 255});
		render->SetPoint(points[i].x, points[i].y);
	}
}

void Polygon::SetPoints(std::vector <Point> points) {

	this->points = points;
}

void Polygon::SetPoint(unsigned id, Point point) {

	if (id < points.size())
		points[id] = point;
}

std::vector <Point> Polygon::GetPolygonPoints() {

	std::vector <Point> border_points;

	for (int i = 0; i < points.size(); ++i) {

		if (i < (points.size() - 1)) {

			LineSegment line(points[i], points[i + 1], r, g , b);
			std::vector <Point> line_points = line.GetLineSegmentPoints();

			border_points.insert(border_points.end(), line_points.begin(), line_points.end());

		}
		else {

			LineSegment line(points[i], points[0], r, g, b);
			std::vector <Point> line_points = line.GetLineSegmentPoints();

			border_points.insert(border_points.end(), line_points.begin(), line_points.end());
		}
	}

	return border_points;
}
