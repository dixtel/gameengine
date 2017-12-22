#include "include/camera.h"

Camera::Camera() {

}

void Camera::DrawScene() {

	render.SetDrawColor(SDL_Color{0, 0, 0, 255});
	render.Clear();
	render.SetDrawColor(SDL_Color{255, 0, 0, 255});

	for(int i = 0; i < world_objects.size(); i++) {

		Point *curr_p = GetObject(i);

		if ((curr_p->x >= minX) && (curr_p->x <= maxX) &&
			(curr_p->y >= minY) && (curr_p->y <= maxY) &&
			(curr_p->z >= minZ) && (curr_p->z <= maxZ)) {

			render.SetPoint(curr_p->x, curr_p->y);
			std::cout << "test\n";
		}
	}

	render.Draw();
}

void Camera::CreateObjects(unsigned size) {

	world_objects.resize(size);
}

void Camera::SetObject(unsigned id, Point object) {

	if (id < world_objects.size())
		world_objects[id] = object;
}

Point *Camera::GetObject(unsigned id) {

	if (id < world_objects.size())
		return &world_objects[id];

	return NULL;
}
