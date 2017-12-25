#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include "include/renderer.h"

class DrawObject {
public:	

	virtual void Draw(Renderer *renderer) = 0;
};

#endif // DRAWOBJECT_H
