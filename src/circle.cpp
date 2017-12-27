#include "include/circle.h"

Circle::Circle(Point position, float radius, unsigned char r, unsigned char g, unsigned char b) {

	this->position = position;
	this->radius = radius;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Circle::Draw(Renderer *render) {

	std::vector <Point> points = GetPointsInBorderCircle();

	for (int i = 0; i < points.size(); ++i) {

		render->SetDrawColor(SDL_Color{r, g, b, 255});
		render->SetPoint(points[i].x, points[i].y);
	}
}

std::vector <Point> Circle::GetPointsInBorderCircle() {

	std::vector <Point> points;

	int m_radius = radius;

	int x = radius-1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (m_radius << 1);

	while (x >= y) {

		points.push_back(Point(position.x + x, position.y + y, 0, r, g, b));
		points.push_back(Point(position.x + y, position.y + x, 0, r, g, b));
		points.push_back(Point(position.x - y, position.y + x, 0, r, g, b));
		points.push_back(Point(position.x - x, position.y + y, 0, r, g, b));
		points.push_back(Point(position.x - x, position.y - y, 0, r, g, b));
		points.push_back(Point(position.x - y, position.y - x, 0, r, g, b));
		points.push_back(Point(position.x + y, position.y - x, 0, r, g, b));
		points.push_back(Point(position.x + x, position.y - y, 0, r, g, b));

		if (err <= 0) {

			y++;
			err += dy;
			dy += 2;
		}
		if (err > 0) {

			x--;
			dx += 2;
			err += dx - (m_radius << 1);
		}
	}

	return points;
}
