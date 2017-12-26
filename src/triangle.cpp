#include "include/triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3) {

	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

void Triangle::Draw(Renderer *render) {

	std::vector <Point> points = GetTrianglePoints();

	for (int i = 0; i < points.size(); ++i) {

		render->SetPoint(points[i].x, points[i].y);
	}
}

std::vector <Point> Triangle::GetTrianglePoints() {

	LineSegment p1p2(p1, p2);
	LineSegment p2p3(p2, p3);
	LineSegment p3p1(p3, p1);

	std::vector <Point> points;
	std::vector <Point> p1p2_points = p1p2.GetLineSegmentPoints();
	std::vector <Point> p2p3_points = p2p3.GetLineSegmentPoints();
	std::vector <Point> p3p1_points = p3p1.GetLineSegmentPoints();

	points.insert(points.end(), p1p2_points.begin(), p1p2_points.end());
	points.insert(points.end(), p2p3_points.begin(), p2p3_points.end());
	points.insert(points.end(), p3p1_points.begin(), p3p1_points.end());

	return points;
}
