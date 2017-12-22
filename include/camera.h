#ifndef CAMERA_H
#define CAMERA_H

#include "include/renderer.h"
#include "include/point.h"

#include <vector>
#include <iostream>

class Camera {
public:
	Camera();

	void DrawScene();
	void CreateObjects(unsigned size);

	void SetObject(unsigned id, Point object);

	Point *GetObject(unsigned id);

	Renderer render;
	int minX, maxX;
	int minY, maxY;
	int minZ, maxZ;

private:
	std::vector <Point> world_objects;
};

#endif // CAMERA_H
