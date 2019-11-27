#include <iostream>
#include"Main_Menu.h"
#include"Game_Play.h"
//#include"Score.h"
#include"Game_State.h"
//#include"PowerUp.h"


void game_play::Initialize(sf::RenderWindow* window) {
	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");

	this->P = new player;
	this->P->setScale(0.5f, 0.5f);
	this->P->setPosition(window->getSize().x /2 - this->P->getGlobalBounds().width/2, window->getSize().y-40);

	this->ballObject = new ball(this->P);
	this->ballObject->setScale(0.5f, 0.5f);
	this->ballObject->setPosition(window->getSize().x / 2 - 15, window->getSize().y / 2 - 30);

}
void game_play::Update(sf::RenderWindow* window) {
	this->P->Update();
	this->ballObject->Update(window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new main_menu());
	}
}
void game_play::Render(sf::RenderWindow* window) {
	window->draw(*this->P);
	window->draw(*this->ballObject);
}
void game_play::Destroy(sf::RenderWindow* window) {
	delete this->P;
	delete this->font;
}
