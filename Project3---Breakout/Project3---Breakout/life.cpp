#include "Life.h"
#include"Game_Obejct.h"
#

life ::life(sf::Font &font, unsigned int size) :sf::Text("Life: 3", font, size) {
	this->health = 3;
}
void life::MinusOne() {
	this->health -= 1;
}
void life::Update() {
	this->setString("Life: " + std::to_string(this->health));
}
void life::hpCheck() {
	if (this->health <= 0) {
		GameOver = true;
		this->health = 3;
	}
}