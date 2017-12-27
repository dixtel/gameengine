
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

	srand(time(NULL));

	Camera camera;

	if (!camera.InitRender(WINDOW_WIDTH, WINDOW_HEIGHT, "gameengine")) {

		return 0;
	}

	camera.SetBorder(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, 0, 100);

	std::vector <Point> polygon_points;

	polygon_points.push_back(Point(0, 0 ,0));
	polygon_points.push_back(Point(300, 50 ,0));
	polygon_points.push_back(Point(350, 200 ,0));
	polygon_points.push_back(Point(260, 390 ,0));
	polygon_points.push_back(Point(200, 150 ,0));
	polygon_points.push_back(Point(100, 50 ,0));
	polygon_points.push_back(Point(50, 50 ,0));
	Polygon polygon(polygon_points);

	camera.AddDrawObject(polygon);

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

					l = true;
				}
				else {

					l = false;
				}
			}
		}

		camera.DrawScene();
	}

	return 0;
}
