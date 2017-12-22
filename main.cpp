
#include "include/point.h"
#include "include/vector.h"
#include "include/camera.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

int main() {

	const unsigned WINDOW_WIDTH = 800;
	const unsigned WINDOW_HEIGHT = 400;
	const int OBJECTS_MAX = 100;

	Camera camera;

	if (!camera.render.Init(WINDOW_WIDTH, WINDOW_HEIGHT, "gameengine")) {

		return 0;
	}

	camera.minX = 0;
	camera.maxX = WINDOW_WIDTH;
	camera.minY = 0;
	camera.maxY = WINDOW_HEIGHT;
	camera.minZ = 0;
	camera.maxZ = 100;

	camera.CreateObjects(OBJECTS_MAX);

	srand(time(NULL));
	for(int i = 0; i < OBJECTS_MAX; ++i) {

		camera.SetObject(i, Point(rand() % 800, rand() % 400, rand() % 200));
	}


	bool running = true;
	SDL_Event event;
	while (running) {

		while(SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT)
				running = false;
			else if (event.key.keysym.sym == SDLK_c) {

				camera.DrawScene();
			}
//			else if (event.key.keysym.sym == SDLK_a) {

//				Point origin(0, 0, 0);

//				for(int i = 0; i < OBJECTS_MAX; ++i) {

//					Vector vec = points[i] - origin;

//					vec = vec.Scale(Vector(0.5, 0.5, 0.5));

//					points[i] = Point(0, 0, 0);

//					points[i] = points[i] + vec;
//				}
//			}
//			else if (event.key.keysym.sym == SDLK_r) {

//				Point origin(0, 0, 0);

//				for(int i = 0; i < OBJECTS_MAX; ++i) {

//					Vector vec = points[i] - origin;

//					vec = vec.RotateXY(15);

//					points[i] = Point(0, 0, 0);

//					points[i] = points[i] + vec;
//				}
//			}
//			else if (event.key.keysym.sym == SDLK_s) {

//				Point origin(0, 0, 0);

//				for(int i = 0; i < OBJECTS_MAX; ++i) {

//					Vector vec = points[i] - origin;

//					vec = vec.Scale(Vector(2,2, 2));

//					points[i] = Point(0, 0, 0);

//					points[i] = points[i] + vec;
//				}
//			}
			else if (event.key.keysym.sym == SDLK_d) {

				camera.render.SetDrawColor(SDL_Color{0, 0, 0, 255});
				camera.render.Clear();

				camera.render.SetDrawColor(SDL_Color{255, 0, 0, 255});
				for(int i = 0; i < OBJECTS_MAX; ++i)
					camera.render.SetPoint(camera.GetObject(i)->x, camera.GetObject(i)->y);

				camera.render.Draw();
			}
		}
	}

	return 0;
}
