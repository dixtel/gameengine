#include "include/vector.h"

Vector::Vector() {

	x = y = x = 0;
}

Vector::Vector(float x, float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

Vector Vector::RotateXY(float degree) {

	float radian_degree = degree * PI / 180;

	Vector transformation(x, y , z);

	transformation.x = cos(radian_degree) * transformation.x - sin(radian_degree) * transformation.x;
	transformation.y = sin(radian_degree) * transformation.y + cos(radian_degree) * transformation.y;

	return transformation;
}

Vector Vector::RotateXZ(float degree) {

	float radian_degree = degree * PI / 180;

	Vector transformation(x, y , z);

	transformation.x = cos(radian_degree) * transformation.x + sin(radian_degree) * transformation.x;
	transformation.z = -sin(radian_degree) * transformation.z + cos(radian_degree) * transformation.z;

	return transformation;
}

Vector Vector::RotateYZ(float degree) {

	float radian_degree = degree * PI / 180;

	Vector transformation(x, y , z);

	transformation.y = cos(radian_degree) * transformation.y - sin(radian_degree) * transformation.y;
	transformation.z = sin(radian_degree) * transformation.z + cos(radian_degree) * transformation.z;

	return transformation;
}

Vector Vector::Scale(Vector scale) {

	return Vector(x * scale.x, y * scale.y, z * scale.z);
}

Vector Vector::operator + (Vector v) {

	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator - (Vector v) {

	return Vector(x - v.x, y - v.y, z - v.z);
}
