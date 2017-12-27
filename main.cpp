
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

	Point point(100, 100, 0, 255, 0, 0);
	Point light_point(50, 50, 0, 255, 255, 255);

	Lighting light(50, 50, 0);
	light.radius = 100;
	light.r = 255;
	light.g = 255;
	light.b = 255;

	bool running = true;
	SDL_Event event;
	while (running) {

		while(SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT)
				running = false;
			else if (event.key.keysym.sym == SDLK_RIGHT) {

				light.x++;
				light_point.x++;
			}
			else if (event.key.keysym.sym == SDLK_LEFT) {

				light.x--;
				light_point.x--;
			}
			else if (event.key.keysym.sym == SDLK_UP) {

				light.y--;
				light_point.y--;
			}
			else if (event.key.keysym.sym == SDLK_DOWN) {

				light.y++;
				light_point.y++;
			}
		}

		camera.ClearScene();
		camera.AddDrawObject(point);
		camera.AddDrawObject(light);
		camera.AddDrawObject(light_point);
		camera.DrawScene();
	}

	return 0;
}
