#include "Player.h"
#include"Game_State.h"


player::player()
{
		this->Load("Player.png");
}

void player::Update() {

	this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);

	Game_Object::Update();

	if (this->getPosition().x < 0)
	{
		this->move(1.0f, 0);
	}
	if (this->getPosition().x + this->getGlobalBounds().width > 800)
	{
		this->move(-1.0f, 0);
	}
	posP = this->getPosition().x + this->getGlobalBounds().width;
}