#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include "include/renderer.h"

#include <vector>

class DrawObject {
public:	

	virtual void Draw(Renderer *render) = 0;
};

#endif // DRAWOBJECT_H
