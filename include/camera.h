#ifndef CAMERA_H
#define CAMERA_H

#include "include/renderer.h"
#include "include/drawobject.h"
#include "include/point.h"
#include "include/linesegment.h"

#include <vector>
#include <iostream>

class Camera {
public:
	Camera();

	bool InitRender(const unsigned window_width, const unsigned window_height, const std::string window_title);
	void DrawScene();
	void AddDrawObject(Point object);
	void AddDrawObject(LineSegment object);

	void SetBorder(int minX, int maxX, int minY, int maxY, int minZ, int maxZ);

private:
	std::vector <Point> points_objects;
	std::vector <LineSegment> linesegments_objects;

	Renderer render;
	int minX, maxX;
	int minY, maxY;
	int minZ, maxZ;
};

#endif // CAMERA_H
