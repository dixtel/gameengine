
#include "include/point.h"
#include "include/vector.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("game engine", 100, 100, 800, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!window || !renderer) {

		SDL_Quit();
		return 0;
	}


	std::vector <Point> points(100);

	for(int i = 0; i < 100; ++i) {

		points[i] = Point(rand() % 800, rand() % 400, 0);
	}

	bool running = true;

	SDL_Event event;

	while (running) {

		while(SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT)
				running = false;
			else if (event.key.keysym.sym == SDLK_a) {

				std::cout << "tets" << std::endl;

				Point origin(0, 0, 0);

				for(int i = 0; i < 100; ++i) {

					Vector vec = points[i] - origin;

					vec = vec.Scale(Vector(0.5, 0.5, 0.5));

					points[i] = Point(0, 0, 0);

					points[i] = points[i] + vec;
				}
			}
			else if (event.key.keysym.sym == SDLK_r) {

				Point origin(0, 0, 0);

				for(int i = 0; i < 100; ++i) {

					Vector vec = points[i] - origin;

					vec = vec.RotateXY(15);

					points[i] = Point(0, 0, 0);

					points[i] = points[i] + vec;
				}
			}
			else if (event.key.keysym.sym == SDLK_s) {

				Point origin(0, 0, 0);

				for(int i = 0; i < 100; ++i) {

					Vector vec = points[i] - origin;

					vec = vec.Scale(Vector(2,2, 2));

					points[i] = Point(0, 0, 0);

					points[i] = points[i] + vec;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		for(int i = 0; i < 100; ++i)
			SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);

		SDL_RenderPresent(renderer);
	}


	SDL_Quit();

	return 0;
}
