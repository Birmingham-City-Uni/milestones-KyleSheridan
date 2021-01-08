#include "PickUp.h"

void PickUp::init()
{
	SDL_Surface* s;

	switch (type)
	{
	case PickUp::Type::DAMAGE:
		s = IMG_Load("assets/DamageUp.png");
		break;
	case PickUp::Type::HEALTH:
		s = IMG_Load("assets/HealthUp.png");
		break;
	case PickUp::Type::FIRERATE:
		s = IMG_Load("assets/FireRateUp.png");
		break;
	case PickUp::Type::RANGE:
		s = IMG_Load("assets/RangeUp.png");
		break;
	case PickUp::Type::HEAL:
		s = IMG_Load("assets/Heal.png");
		break;
	default:
		std::cout << "Error initialising PickUp" << std::endl;
		s = nullptr;
		break;
	}

	texture = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);

	collider = { position.x + (position.w / 2), position.y + (position.h / 2), position.w / 2 };
}

void PickUp::update()
{
	if (collider.isColliding(player->getPosition().x + (player->getPosition().w / 2), player->getPosition().y + (player->getPosition().h / 2))) {
		pickUpEffect();
	}
}

void PickUp::draw()
{
	SDL_RenderCopy(renderer, texture, NULL, &position);
}

void PickUp::pickUpEffect() {
	switch (type)
	{
	case PickUp::Type::DAMAGE:
		player->increaseDamage();
		collected = true;
		break;
	case PickUp::Type::HEALTH:
		player->increaseHealth();
		collected = true;
		break;
	case PickUp::Type::FIRERATE:
		player->increaseFireRate();
		collected = true;
		break;
	case PickUp::Type::RANGE:
		player->increaseRange();
		collected = true;
		break;
	case PickUp::Type::HEAL:
		player->takeDamage(-20);
		collected = true;
		break;
	default:
		std::cout << "Error colliding wwith PickUp" << std::endl;
		break;
	}
}