#include "include/camera.h"

Camera::Camera() {

}

bool Camera::InitRender(const unsigned window_width, const unsigned window_height, const std::string window_title) {

	return render.Init(window_width, window_height, window_title);
}

void Camera::DrawScene() {

	render.SetDrawColor(SDL_Color{0, 0, 0, 255});
	render.Clear();
	render.SetDrawColor(SDL_Color{255, 0, 0, 255});

	for(int i = 0; i < point_objects.size(); i++) {

		Point point = point_objects[i];

		if ((point.x >= minX) && (point.x <= maxX) &&
			(point.y >= minY) && (point.y <= maxY) &&
			(point.z >= minZ) && (point.z <= maxZ)) {

			DrawObject *drawobject = &point;
			drawobject->Draw(&render);
		}
	}

	for(int i = 0; i < linesegment_objects.size(); i++) {

		LineSegment linesegment = linesegment_objects[i];

		if ((linesegment.start.x >= minX) && (linesegment.start.x <= maxX) &&
			(linesegment.start.y >= minY) && (linesegment.start.y <= maxY) &&
			(linesegment.start.z >= minZ) && (linesegment.start.z <= maxZ) ) {

			DrawObject *drawobject = &linesegment;
			drawobject->Draw(&render);
		}
		else if ((linesegment.end.x >= minX) && (linesegment.end.x <= maxX) &&
				(linesegment.end.y >= minY) && (linesegment.end.y <= maxY) &&
				(linesegment.end.z >= minZ) && (linesegment.end.z <= maxZ) ) {

			DrawObject *drawobject = &linesegment;
			drawobject->Draw(&render);
		}
	}

	for(int i = 0; i < circle_objects.size(); i++) {

		Circle circle = circle_objects[i];

		if ((circle.position.x >= minX) && (circle.position.x <= maxX) &&
			(circle.position.y >= minY) && (circle.position.y <= maxY) &&
			(circle.position.z >= minZ) && (circle.position.z <= maxZ)) {

			DrawObject *drawobject = &circle;
			drawobject->Draw(&render);
		}
	}

	for(int i = 0; i < triangle_objects.size(); i++) {

		Triangle triangle = triangle_objects[i];

		if ((triangle.p1.x >= minX) && (triangle.p1.x <= maxX) &&
			(triangle.p1.y >= minY) && (triangle.p1.y <= maxY) &&
			(triangle.p1.z >= minZ) && (triangle.p1.z <= maxZ)) {

			DrawObject *drawobject = &triangle;
			drawobject->Draw(&render);
		}
		else if ((triangle.p2.x >= minX) && (triangle.p2.x <= maxX) &&
				 (triangle.p2.y >= minY) && (triangle.p2.y <= maxY) &&
				 (triangle.p2.z >= minZ) && (triangle.p2.z <= maxZ)) {

			DrawObject *drawobject = &triangle;
			drawobject->Draw(&render);
		}
		else if ((triangle.p3.x >= minX) && (triangle.p3.x <= maxX) &&
				 (triangle.p3.y >= minY) && (triangle.p3.y <= maxY) &&
				 (triangle.p3.z >= minZ) && (triangle.p3.z <= maxZ)) {

			DrawObject *drawobject = &triangle;
			drawobject->Draw(&render);
		}
	}

	for(int i = 0; i < quad_objects.size(); i++) {

		Quad quad = quad_objects[i];

		if ((quad.p1.x >= minX) && (quad.p1.x <= maxX) &&
			(quad.p1.y >= minY) && (quad.p1.y <= maxY) &&
			(quad.p1.z >= minZ) && (quad.p1.z <= maxZ)) {

			DrawObject *drawobject = &quad;
			drawobject->Draw(&render);
		}
		else if ((quad.p2.x >= minX) && (quad.p2.x <= maxX) &&
				 (quad.p2.y >= minY) && (quad.p2.y <= maxY) &&
				 (quad.p2.z >= minZ) && (quad.p2.z <= maxZ)) {

			DrawObject *drawobject = &quad;
			drawobject->Draw(&render);
		}
		else if ((quad.p3.x >= minX) && (quad.p3.x <= maxX) &&
				 (quad.p3.y >= minY) && (quad.p3.y <= maxY) &&
				 (quad.p3.z >= minZ) && (quad.p3.z <= maxZ)) {

			DrawObject *drawobject = &quad;
			drawobject->Draw(&render);
		}
		else if ((quad.p4.x >= minX) && (quad.p4.x <= maxX) &&
				 (quad.p4.y >= minY) && (quad.p4.y <= maxY) &&
				 (quad.p4.z >= minZ) && (quad.p4.z <= maxZ)) {

			DrawObject *drawobject = &quad;
			drawobject->Draw(&render);
		}
	}

	render.Draw();
}

void Camera::AddDrawObject(Point object) {

	point_objects.push_back(object);
}

void Camera::AddDrawObject(LineSegment object) {

	linesegment_objects.push_back(object);
}

void Camera::AddDrawObject(Circle object) {

	circle_objects.push_back(object);
}

void Camera::AddDrawObject(Triangle object) {

	triangle_objects.push_back(object);
}

void Camera::AddDrawObject(Quad object) {

	quad_objects.push_back(object);
}

void Camera::SetBorder(int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {

	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	this->minZ = minZ;
	this->maxZ = maxZ;
}
