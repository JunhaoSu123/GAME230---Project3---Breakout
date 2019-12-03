#include <iostream>
#include"WinState.h"
#include"Game_Play.h"
#include"Ball.h"
#include"Main_Menu.h"
#include"Score.h"
#include"Game_Obejct.h"
#include"Game_State.h"
#include"Game_Play.h"


void win_state::Initialize(sf::RenderWindow* window) {

	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");

	this->gameOver = new sf::Text("Game Over", *this->font, 100U);
	this->gameOver->setOrigin(this->gameOver->getGlobalBounds().width / 2, this->gameOver->getGlobalBounds().height / 2);
	this->gameOver->setPosition(window->getSize().x / 2, window->getSize().y / 5);

	this->esc = new sf::Text("Press ESC to back to main menu", *this->font, 32U);
	this->esc->setOrigin(this->esc->getGlobalBounds().width / 2, this->esc->getGlobalBounds().height / 2);
	this->esc->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 140);

	this->bufferLose = new sf::SoundBuffer();
	this->bufferLose->loadFromFile("Sounds/you_lose.wav");
	this->soundLose = new sf::Sound(*this->bufferLose);
	this->soundLose->play();
}
void win_state::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new main_menu());
	
	}
}
void win_state::Render(sf::RenderWindow* window) {

	this->gameOver->setFillColor(sf::Color::White);
	this->esc->setFillColor(sf::Color::White);
	window->draw(*this->gameOver);
	window->draw(*this->esc);

}

void win_state::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->gameOver;
	delete this->esc;
	delete this->soundLose;
	delete this->bufferLose;
}
