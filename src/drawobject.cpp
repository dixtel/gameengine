#include "include/drawobject.h"

void DrawObject::ApplyingLighting(std::vector <Lighting> lighting_objects) {

	this->lighting_objects = lighting_objects;
}

std::vector <Lighting> DrawObject::GetLighting() {

	return lighting_objects;
}
