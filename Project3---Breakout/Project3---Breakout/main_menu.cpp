#include <iostream>
#include"Main_Menu.h"
#include"Game_State.h"
#include"Game_Play.h"

bool obActive = false;
bool aiActive = false;
bool hoActive = false;
void main_menu::Initialize(sf::RenderWindow* window) {

	this->ButtonSelect = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");

	this->title1 = new sf::Text("Break", *this->font, 128U);
	this->title1->setOrigin(this->title1->getGlobalBounds().width / 2+60, this->title1->getGlobalBounds().height / 2);
	this->title1->setPosition(window->getSize().x / 2, window->getSize().y / 5);

	this->title2 = new sf::Text("Out", *this->font, 128U);
	this->title2->setOrigin(this->title2->getGlobalBounds().width / 2-180, this->title2->getGlobalBounds().height / 2);
	this->title2->setPosition(window->getSize().x / 2, window->getSize().y / 5 + 120);

	this->play = new sf::Text("Play", *this->font, 64U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 120);

	this->quit = new sf::Text("Quit", *this->font, 64U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 240);

}
void main_menu::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->Upkey) {
		this->ButtonSelect -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->Downkey) {
		this->ButtonSelect += 1;
	}
	if (this->ButtonSelect > 1) {
		this->ButtonSelect = 0;
	}
	if (this->ButtonSelect < 0) {
		this->ButtonSelect = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		switch (this->ButtonSelect) {
		case 0:
			coreState.SetState(new game_play());
			getPU = true;
			break;
		case 1:
			quitGame = true;
			break;
		}
	}
	this->Upkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->Downkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

}
void main_menu::Render(sf::RenderWindow* window) {

	this->play->setFillColor(sf::Color::White);
	this->quit->setFillColor(sf::Color::White);


	switch (this->ButtonSelect) {
	case 0:
		this->play->setFillColor(sf::Color::Red);
		break;
	case 1:
		this->quit->setFillColor(sf::Color::Red);
		break;
	}

	window->draw(*this->title1);
	window->draw(*this->title2);
	window->draw(*this->play);
	window->draw(*this->quit);
}
void main_menu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title1;
	delete this->title2;
	delete this->play;;
	delete this->quit;
}
