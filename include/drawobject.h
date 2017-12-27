#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include "include/renderer.h"
#include "include/lighting.h"

#include <vector>

class DrawObject {
public:	
	DrawObject() {}
	virtual ~DrawObject() {}

	virtual void Draw(Renderer *render) = 0;
	void ApplyingLighting(std::vector <Lighting> lighting_objects);

	std::vector <Lighting> GetLighting();

private:
	std::vector <Lighting> lighting_objects;
};

#endif // DRAWOBJECT_H
