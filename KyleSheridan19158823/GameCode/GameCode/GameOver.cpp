#include "GameOver.h"

void GameOver::init()
{
	background = new Background(renderer);
	background->init();

	gameOver = new Text(renderer, 72);
	scoreText = new Text(renderer, 32);
}

void GameOver::draw()
{
	background->draw();

	gameOver->draw("GAME OVER", Text::alignX::CENTRE, 200);
	scoreText->draw(string("Final Score: " + to_string(score)).c_str(), Text::alignX::CENTRE, 500);
}


