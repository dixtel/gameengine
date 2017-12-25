
#include "include/point.h"
#include "include/vector.h"
#include "include/camera.h"
#include "include/linesegment.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

int main() {

	//LineSegment line(Point(0, 0, 0), Point(200, 250, 0));
	LineSegment line(Point(250, 250, 0), Point(500, 250, 0));

	std::cout << line.start << " " << line.end << std::endl;

	const unsigned WINDOW_WIDTH = 800;
	const unsigned WINDOW_HEIGHT = 400;

	Camera camera;

	if (!camera.InitRender(WINDOW_WIDTH, WINDOW_HEIGHT, "gameengine")) {

		return 0;
	}

	camera.SetBorder(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, 0, 100);

	std::vector <Point> points_objects;
	std::vector <LineSegment> linesegmets_objects;

	srand(time(NULL));
	for(int i = 0; i < 20; ++i) {

		points_objects.push_back(Point(rand() % 800, rand() % 400, rand() % 200));
		linesegmets_objects.push_back(LineSegment(Point(rand() % 800, rand() % 400, rand() % 200), Point(rand() % 800, rand() % 400, rand() % 200)));
	}

	for(int i = 0; i < 20; ++i) {

		camera.AddDrawObject(points_objects[i]);
		camera.AddDrawObject(linesegmets_objects[i]);
	}


	bool running = true;
	SDL_Event event;
	while (running) {

		while(SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT)
				running = false;
		}

		camera.DrawScene();
	}

	return 0;
}
