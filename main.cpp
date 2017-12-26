
#include "include/point.h"
#include "include/vector.h"
#include "include/camera.h"
#include "include/linesegment.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

int main() {

	const unsigned WINDOW_WIDTH = 800;
	const unsigned WINDOW_HEIGHT = 400;

	Camera camera;

	if (!camera.InitRender(WINDOW_WIDTH, WINDOW_HEIGHT, "gameengine")) {

		return 0;
	}

	camera.SetBorder(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, 0, 100);

	std::vector <Circle> circle_objects;
	LineSegment line(Point(100, 100, 0), Point(400, 200, 0));

	camera.AddDrawObject(line);

	srand(time(NULL));


	bool running = true;
	SDL_Event event;
	while (running) {

		while(SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_MOUSEBUTTONDOWN) {

				static bool l = false;

				int x, y;
				SDL_GetMouseState(&x, &y);

				if (l == false) {
					line.start = Point(x, y, 0);
					l = true;
				}
				else {
					line.end = Point(x, y, 0);
					l = false;
					camera.AddDrawObject(line);
				}
			}
		}

		camera.DrawScene();
	}

	return 0;
}
