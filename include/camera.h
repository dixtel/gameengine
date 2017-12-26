#ifndef CAMERA_H
#define CAMERA_H

#include "include/renderer.h"
#include "include/drawobject.h"
#include "include/point.h"
#include "include/linesegment.h"
#include "include/circle.h"
#include "include/triangle.h"
#include "include/quad.h"

#include <vector>
#include <iostream>

class Camera {
public:
	Camera();

	bool InitRender(const unsigned window_width, const unsigned window_height, const std::string window_title);
	void DrawScene();
	void AddDrawObject(Point object);
	void AddDrawObject(LineSegment object);
	void AddDrawObject(Circle object);
	void AddDrawObject(Triangle object);
	void AddDrawObject(Quad object);

	void SetBorder(int minX, int maxX, int minY, int maxY, int minZ, int maxZ);

private:
	std::vector <Point> point_objects;
	std::vector <LineSegment> linesegment_objects;
	std::vector <Circle> circle_objects;
	std::vector <Triangle> triangle_objects;
	std::vector <Quad> quad_objects;

	Renderer render;
	int minX, maxX;
	int minY, maxY;
	int minZ, maxZ;
};

#endif // CAMERA_H
