#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <string>

class Renderer {
public:
	Renderer();
	~Renderer();

	bool Init(const unsigned window_width, const unsigned window_height, const std::string window_title);

	void SetPoint(int x, int y);
	void Clear();
	void Draw();
	void SetDrawColor(SDL_Color color);

private:
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	unsigned window_width;
	unsigned window_height;
	std::string window_title;
};

#endif // RENDERER_H
