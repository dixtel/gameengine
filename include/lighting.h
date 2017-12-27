#ifndef LIGHTING_H
#define LIGHTING_H

#include <string>

enum LIGHTING_TYPE {

	LIGHTING_TYPE_POINT
};

class Lighting {
public:
	Lighting(float x, float y, float z);

	float x;
	float y;
	float z;
	unsigned char r = 255;
	unsigned char g = 255;
	unsigned char b = 255;
	float radius = 50;
	LIGHTING_TYPE type = LIGHTING_TYPE_POINT;
};

#endif // LIGHTING_H
