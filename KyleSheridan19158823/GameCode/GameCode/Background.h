#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Background {
public:
	//constrctor
	Background(SDL_Renderer*);
	//called at the start of the program
	void init();
	//called every frame
	void update();
	//called every frame
	void draw();
	//called on program shutdown
	void clear();

private:
	SDL_Texture* texture; //this is the players sprite
	SDL_Renderer* renderer; //allows rendering from this class

	SDL_Rect position;
};