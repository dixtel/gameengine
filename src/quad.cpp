#include "include/quad.h"

Quad::Quad(Point p1, Point p2, Point p3, Point p4, unsigned char r, unsigned char g, unsigned char b) {

	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Quad::Draw(Renderer *render) {

	std::vector <Point> points = GetQuadPoints();

	for (int i = 0; i < points.size(); ++i) {

		render->SetDrawColor(SDL_Color{r, g, b, 255});
		render->SetPoint(points[i].x, points[i].y);
	}
}

std::vector <Point> Quad::GetQuadPoints() {

	LineSegment p1p2(p1, p2, r, g, b);
	LineSegment p2p3(p2, p3, r, g, b);
	LineSegment p3p4(p3, p4, r, g, b);
	LineSegment p4p1(p4, p1, r, g, b);

	std::vector <Point> points;
	std::vector <Point> p1p2_points = p1p2.GetLineSegmentPoints();
	std::vector <Point> p2p3_points = p2p3.GetLineSegmentPoints();
	std::vector <Point> p3p4_points = p3p4.GetLineSegmentPoints();
	std::vector <Point> p4p1_points = p4p1.GetLineSegmentPoints();

	points.insert(points.end(), p1p2_points.begin(), p1p2_points.end());
	points.insert(points.end(), p2p3_points.begin(), p2p3_points.end());
	points.insert(points.end(), p3p4_points.begin(), p3p4_points.end());
	points.insert(points.end(), p4p1_points.begin(), p4p1_points.end());

	return points;
}
