#include "Ball.h"
#include"Game_State.h"
#include"Main_Menu.h"
#include"Player.h"
#include<math.h>

bool getOb = false;
bool getho = false;
bool whoWon;
float power;
float distance;
float ballCenter;
float posP;
float v;
ball::ball(player* P) {
	this->Load("Ball.png");

	this->P = P;

	this->velocity.x = 0.6f;
	this->velocity.y = 1.0f;

	v = sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y);


	this->bufferBounce = new sf::SoundBuffer();
	this->bufferBounce->loadFromFile("Sounds/WaterDrop.wav");
	this->soundBounce = new sf::Sound(*this->bufferBounce);
}

void ball::Update(sf::RenderWindow* window) {
	if (this->velocity.y > 0 && this->CollisionCheck(this->P)) {
		this->soundBounce->play();
		if (ballCenter < posP - this->P->getGlobalBounds().width / 3*2) {
			if (this->velocity.x > 0) {
				//this->velocity.y -= (posP - this->P->getGlobalBounds().width / 3 * 2 - ballCenter)/10;
				//this->velocity.x += (posP - this->P->getGlobalBounds().width / 3 * 2 - ballCenter) / 10;
				this->velocity.x *= -1;
			}
			if (this->velocity.x < 0) {
				this->velocity.x *= 1;
			}
		}

		if (ballCenter > posP-this->P->getGlobalBounds().width/3) {
			if (this->velocity.x < 0) {
				this->velocity.x *= -1;
			}
			if (this->velocity.x > 0) {
				this->velocity.x *= 1;
			}
		}
		this->velocity.y *= -1.0f;
	}
	if (this->getPosition().y < 0 || this->getPosition().y > window->getSize().y - this->getGlobalBounds().height) {
		this->soundBounce->play();
		this->velocity.y *= -1.0f;
	}

	if (this->getPosition().x < 0 || this->getPosition().x > window->getSize().x - this->getGlobalBounds().width) {
		this->soundBounce->play();
		//this->setPosition(window->getSize().x / 2 - 50, window->getSize().y / 2 - 30);
		this->velocity.x *= -1.0f;
	}

	Game_Object::Update();
	ballCenter = this->getPosition().x + this->getGlobalBounds().width / 2;
}
ball::~ball() {
	delete this->bufferBounce;
	delete this->soundBounce;
}