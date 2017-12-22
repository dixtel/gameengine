#include "include/renderer.h"

Renderer::Renderer() {

	SDL_Init(SDL_INIT_EVERYTHING);
}

Renderer::~Renderer() {

	SDL_Quit();
}

bool Renderer::Init(const unsigned window_width, const unsigned window_height, const std::string window_title) {

	this->window_width = window_width;
	this->window_height = window_height;
	this->window_title = window_title;

	window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, NULL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!window || !renderer)
		return false;

	return true;
}

void Renderer::SetPoint(int x, int y) {

	SDL_RenderDrawPoint(renderer, x, y);
}

void Renderer::Clear() {

	SDL_RenderClear(renderer);
}

void Renderer::Draw() {

	SDL_RenderPresent(renderer);
}

void Renderer::SetDrawColor(SDL_Color color) {

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}
