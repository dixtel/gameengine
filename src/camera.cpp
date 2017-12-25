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

	for(int i = 0; i < points_objects.size(); i++) {

		Point point = points_objects[i];

		if ((point.x >= minX) && (point.x <= maxX) &&
			(point.y >= minY) && (point.y <= maxY) &&
			(point.z >= minZ) && (point.z <= maxZ)) {

			DrawObject *drawobject = &point;
			drawobject->Draw(&render);
		}
	}

	for(int i = 0; i < linesegments_objects.size(); i++) {

		LineSegment linesegment = linesegments_objects[i];

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

	render.Draw();
}

void Camera::AddDrawObject(Point object) {

	points_objects.push_back(object);
}

void Camera::AddDrawObject(LineSegment object) {

	linesegments_objects.push_back(object);
}

void Camera::SetBorder(int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {

	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	this->minZ = minZ;
	this->maxZ = maxZ;
}
