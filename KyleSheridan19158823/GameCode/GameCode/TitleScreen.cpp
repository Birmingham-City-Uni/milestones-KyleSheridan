#include "TitleScreen.h"

TitleScreen::TitleScreen(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void TitleScreen::init()
{
	//create Background
	background = new Background(this->renderer);
	background->init();

	title = new Text(renderer, 55);
}

void TitleScreen::input()
{

}

void TitleScreen::update()
{

}

void TitleScreen::draw()
{
	//process drawing for classes
	background->draw();

	title->draw("TITLE TEST", Text::alignX::CENTRE, 200);
}

void TitleScreen::clear()
{
	background->clear();
	if (background) {
		delete background;
		background = nullptr;;
	}
}