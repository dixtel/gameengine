#include "include/point.h"

Point::Point() {

	x = y = z = 0;
}

Point::Point(float x, float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point(float x, float y, float z, unsigned char r, unsigned char g, unsigned char b) {

	this->x = x;
	this->y = y;
	this->z = z;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Point::Draw(Renderer *render) {

	std::vector <Lighting> lighting_objects = GetLighting();

	int copy_r = r;
	int copy_g = g;
	int copy_b = b;

	for (int i = 0; i < lighting_objects.size(); ++i) {

		Point lighting_pos = Point(lighting_objects[i].x, lighting_objects[i].y, lighting_objects[i].z);
		float radius = lighting_objects[i].radius;
		float distance = std::sqrt(std::pow(lighting_pos.x - x, 2) + std::pow(lighting_pos.y - y, 2));

		if (distance <= radius) {

			float percentage = 1 - (distance / radius);
			copy_r += percentage * lighting_objects[i].r;
			copy_g += percentage * lighting_objects[i].g;
			copy_b += percentage * lighting_objects[i].b;

			if (copy_r > 255)
				copy_r = 255;

			if (copy_g > 255)
				copy_g = 255;

			if (copy_b > 255)
				copy_b = 255;
		}
	}

	render->SetDrawColor(SDL_Color{copy_r, copy_g, copy_b, 255});
	render->SetPoint(x, y);
}

Point Point::operator + (Vector v) {

	return Point(x + v.x, y + v.y, z + v.z);
}

Point Point::operator - (Vector v) {

	return Point(x - v.x, y - v.y, z - v.z);
}

Vector Point::operator - (Point p) {

	return Vector(x - p.x, y - p.y, z - p.z);
}

void Point::operator = (Point p) {

	x = p.x;
	y = p.y;
	z = p.z;
}
