#ifndef VECTOR_H
#define VECTOR_H

#define PI 3.14159265

#include <cmath>
#include <iostream>

class Vector {
public:
	Vector();
	Vector(float x, float y, float z);

	Vector RotateXY(float degree);
	Vector RotateXZ(float degree);
	Vector RotateYZ(float degree);

	Vector Scale(Vector scale);

	Vector operator + (Vector v);
	Vector operator - (Vector v);

	friend std::ostream &operator << (std::ostream &stream, const Vector &v) {

		stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return stream;
	}

	float x;
	float y;
	float z;
};

#endif // VECTOR_H
