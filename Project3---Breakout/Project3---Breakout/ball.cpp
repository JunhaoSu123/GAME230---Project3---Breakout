#include "Ball.h"
#include"Game_State.h"
#include"Main_Menu.h"
#include"Player.h"
#include"Brick.h"
#include<math.h>
#include<iostream>
using namespace std;
int ballS = 0;
bool started = false;
bool brk = true;
bool brk1= true;
bool brk2= true;
bool brk3= true;
bool brk4= true;
bool brk5= true;
bool brk6= true;
bool brk7= true;
bool brk8= true;
bool brk9= true;
bool brk10= true;
bool brk11= true;
bool brk12= true;
bool brk13= true;
bool brk14= true;
bool brk15= true;
bool brk16= true;
bool brk17= true;
bool brk18= true;
bool brk19= true;
bool brk20= true;
bool brk21= true;
bool brk22= true;
bool brk23= true;
bool brk24= true;
bool brk25= true;
bool brk26= true;
bool brk27= true;
bool brk28= true;
bool brk29= true;
bool brk30= true;
bool brk31= true;
bool brk32= true;
bool brk33= true;
bool brk34= true;
bool brk35= true;
float power;
float distance;
float ballCenter;
float posP;
float v;
ball::ball(player* P, 
	brick* bk, 
	brick* bk1,
	brick* bk2,
	brick* bk3,
	brick* bk4,
	brick* bk5,
	brick* bk6,
	brick* bk7,
	brick* bk8,
	brick* bk9,
	brick* bk10,
	brick* bk11,
	brick* bk12,
	brick* bk13,
	brick* bk14,
	brick* bk15,
	brick* bk16,
	brick* bk17,
	brick* bk18,
	brick* bk19,
	brick* bk20,
	brick* bk21,
	brick* bk22,
	brick* bk23,
	brick* bk24,
	brick* bk25,
	brick* bk26,
	brick* bk27,
	brick* bk28,
	brick* bk29,
	brick* bk30,
	brick* bk31,
	brick* bk32,
	brick* bk33,
	brick* bk34,
	brick* bk35,
	score* sc,
	life* hp) {
	this->Load("Ball.png");

	this->P = P;
	this->bk = bk;
	this->bk1 = bk1;
	this->bk2 = bk2;
	this->bk3 = bk3;
	this->bk4 = bk4;
	this->bk5 = bk5;
	this->bk6 = bk6;
	this->bk7 = bk7;
	this->bk8 = bk8;
	this->bk9 = bk9;
	this->bk10 = bk10;
	this->bk11 = bk11;
	this->bk12 = bk12;
	this->bk13 = bk13;
	this->bk14 = bk14;
	this->bk15 = bk15;
	this->bk16 = bk16;
	this->bk17 = bk17;
	this->bk18 = bk18;
	this->bk19 = bk19;
	this->bk20 = bk20;
	this->bk21 = bk21;
	this->bk22 = bk22;
	this->bk23 = bk23;
	this->bk24 = bk24;
	this->bk25 = bk25;
	this->bk26 = bk26;
	this->bk27 = bk27;
	this->bk28 = bk28;
	this->bk29 = bk29;
	this->bk30 = bk30;
	this->bk31 = bk31;
	this->bk32 = bk32;
	this->bk33 = bk33;
	this->bk34 = bk34;
	this->bk35 = bk35;
	this->sc = sc;
	this->hp = hp;
	this->velocity.x = 1.8f;
	this->velocity.y = -3.0f;

	v = this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y;


	this->bufferBounce = new sf::SoundBuffer();
	this->bufferBounce->loadFromFile("Sounds/paddleBounce.wav");
	this->soundBounce = new sf::Sound(*this->bufferBounce);

	this->bufferWallBounce = new sf::SoundBuffer();
	this->bufferWallBounce->loadFromFile("Sounds/wallBounce.ogg");
	this->soundWallBounce = new sf::Sound(*this->bufferWallBounce);

	this->bufferLose = new sf::SoundBuffer();
	this->bufferLose->loadFromFile("Sounds/lose.wav");
	this->soundLose = new sf::Sound(*this->bufferLose);

	this->bufferBrick = new sf::SoundBuffer();
	this->bufferBrick->loadFromFile("Sounds/brick.ogg");
	this->soundBrick = new sf::Sound(*this->bufferBrick);
}

void ball::Update(sf::RenderWindow* window) {

	if (!started) {
		if (this->getPosition().x + this->getGlobalBounds().width / 2 <= this->P->getPosition().x + this->P->getGlobalBounds().width / 2 || this->getPosition().x + this->getGlobalBounds().width / 2 >= this->P->getPosition().x + this->P->getGlobalBounds().width / 2) {
			this->setPosition(this->P->getPosition().x + this->P->getGlobalBounds().width / 2, window->getSize().y - 42- this->P->getGlobalBounds().height);
			if (this->velocity.y > 0) {
				this->velocity.y *= -1;
			}
		}
	}
	if (ballS < speed) {
		this->velocity.y *= 1.2f;
		this->velocity.x *= 1.2f;
		v *= 1.2f;
		ballS = speed;
	}
	if (brk == true && this->CollisionCheck(this->bk)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk = false;
		this->sc->PlusOne();
	}
	if (brk1 == true && this->CollisionCheck(this->bk1)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk1 = false;
		this->sc->PlusOne();
	}
	if (brk2 == true && this->CollisionCheck(this->bk2)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk2 = false;
		this->sc->PlusOne();
	}
	if (brk3 == true && this->CollisionCheck(this->bk3)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk3 = false;
		this->sc->PlusOne();
	}
	if (brk4 == true && this->CollisionCheck(this->bk4)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk4 = false;		
		this->sc->PlusOne();
	}
	if (brk5 == true && this->CollisionCheck(this->bk5)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk5 = false;		
		this->sc->PlusOne();
	}
	if (brk6 == true && this->CollisionCheck(this->bk6)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk6 = false;		
		this->sc->PlusOne();
	}
	if (brk7 == true && this->CollisionCheck(this->bk7)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk7 = false;		
		this->sc->PlusOne();
	}
	if (brk8 == true && this->CollisionCheck(this->bk8)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk8 = false;		
		this->sc->PlusOne();
	}
	if (brk9 == true && this->CollisionCheck(this->bk9)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk9 = false;		
		this->sc->PlusOne();
	}
	if (brk10 == true && this->CollisionCheck(this->bk10)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk10 = false;		
		this->sc->PlusOne();
	}
	if (brk11 == true && this->CollisionCheck(this->bk11)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk11 = false;		
		this->sc->PlusOne();
	}
	if (brk12 == true && this->CollisionCheck(this->bk12)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk12 = false;		
		this->sc->PlusOne();
	}
	if (brk13 == true && this->CollisionCheck(this->bk13)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk13 = false;		
		this->sc->PlusOne();
	}
	if (brk14 == true && this->CollisionCheck(this->bk14)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk14 = false;		
		this->sc->PlusOne();
	}
	if (brk15 == true && this->CollisionCheck(this->bk15)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk15 = false;		
		this->sc->PlusOne();
	}
	if (brk16 == true && this->CollisionCheck(this->bk16)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk16 = false;		
		this->sc->PlusOne();
	}
	if (brk17 == true && this->CollisionCheck(this->bk17)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk17 = false;		
		this->sc->PlusOne();
	}
	if (brk18 == true && this->CollisionCheck(this->bk18)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk18 = false;		
		this->sc->PlusOne();
	}
	if (brk19 == true && this->CollisionCheck(this->bk19)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk19 = false;	
		getPU = false;
		this->sc->PlusOne();
	}
	if (brk20 == true && this->CollisionCheck(this->bk20)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk20 = false;		
		this->sc->PlusOne();
	}
	if (lvl2 == true && brk20 == false && this->velocity.y < 0 && this->CollisionCheck(this->bk20)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
	}
	if (brk21 == true && this->CollisionCheck(this->bk21)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk21 = false;		
		this->sc->PlusOne();
	}
	if (lvl2 == true && brk21 == false && this->velocity.y < 0 && this->CollisionCheck(this->bk20)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
	}
	if (brk22 == true && this->CollisionCheck(this->bk22)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk22 = false;		
		this->sc->PlusOne();
	}
	if (brk23 == true && this->CollisionCheck(this->bk23)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk23 = false;		
		this->sc->PlusOne();
	}
	if (brk24 == true && this->CollisionCheck(this->bk24)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk24 = false;		
		this->sc->PlusOne();
	}
	if (lvl3 == true && brk24 == false && this->CollisionCheck(this->bk24)) {
		this->velocity.y *= -1;
	}

	if (brk25 == true && this->CollisionCheck(this->bk25)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		this->soundBrick->play();
		brk25 = false;		
		this->sc->PlusOne();
	}
	if (brk26 == true && this->CollisionCheck(this->bk26)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk26 = false;	
		this->sc->PlusOne();
	}
	if (brk27 == true && this->CollisionCheck(this->bk27)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk27 = false;		
		this->sc->PlusOne();
	}
	if (brk28 == true && this->CollisionCheck(this->bk28)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk28 = false;		
		this->sc->PlusOne();
	}
	if (brk29 == true && this->CollisionCheck(this->bk29)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk29 = false;		
		this->sc->PlusOne();
	}
	if (lvl3 == true && brk29 == false && this->CollisionCheck(this->bk24)) {
		this->velocity.y *= -1;
	}
	if (brk30 == true && this->CollisionCheck(this->bk30)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk30 = false;		
		this->sc->PlusOne();
	}
	if (brk31 == true && this->CollisionCheck(this->bk31)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk31 = false;		
		this->sc->PlusOne();
	}
	if (brk32 == true && this->CollisionCheck(this->bk32)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk32 = false;		
		this->sc->PlusOne();
	}
	if (brk33 == true && this->CollisionCheck(this->bk33)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk33 = false;		
		this->sc->PlusOne();
	}
	if (brk34 == true && this->CollisionCheck(this->bk34)) {
		this->velocity.y *= -1;
		this->soundBrick->play();
		brk34 = false;		
		this->sc->PlusOne();
	}
	if (brk35 == true && this->CollisionCheck(this->bk35)) {
		this->velocity.y *= -1;
		
		this->soundBrick->play();
		brk35 = false;		
		this->sc->PlusOne();
	}

	if (this->velocity.y > 0 && this->CollisionCheck(this->P)) {
		this->soundBounce->play();
		if (ballCenter < posP - this->P->getGlobalBounds().width / 3*2) {
			if (this->velocity.x > 0) {
				this->velocity.y -= (posP - this->P->getGlobalBounds().width / 3 * 2 - ballCenter)/100;
				if (this->velocity.y < 0.42f) {
					this->velocity.y = 0.42f;
				}
				this->velocity.x = sqrt(v - this->velocity.y * this->velocity.y);
				cout << "speed y = " << this->velocity.y << endl;
				cout << "speed x = " << this->velocity.x << endl;
				this->velocity.x *= -1;
			}
			else if (this->velocity.x < 0) {
				this->velocity.y += 1.2f;
				if (this->velocity.y > 3.25f) {
					this->velocity.y = 3.25f;
				}
				this->velocity.x = sqrt(v - this->velocity.y * this->velocity.y);
				cout << "speed y = " << this->velocity.y << endl;
				cout << "speed x = " << this->velocity.x << endl;
				this->velocity.x *= -1;
			}
		}

		if (ballCenter > posP-this->P->getGlobalBounds().width/3) {
			if (this->velocity.x < 0) {
				this->velocity.y -= (ballCenter - posP + this->P->getGlobalBounds().width / 3) / 100;
				if (this->velocity.y < 1.26f) {
					this->velocity.y = 1.26f;
				}
				this->velocity.x = sqrt(v - this->velocity.y * this->velocity.y);
				cout << "speed y = " << this->velocity.y << endl;
				cout << "speed x = " << this->velocity.x << endl;
			}
			else if (this->velocity.x > 0) {
				this->velocity.y += 1.2f;
				if (this->velocity.y > 3.25f) {
					this->velocity.y = 3.25f;
				}
				this->velocity.x = sqrt(v - this->velocity.y * this->velocity.y);
				cout << "speed y = " << this->velocity.y << endl;
				cout << "speed x = " << this->velocity.x << endl;
				this->velocity.x *= -1;
				this->velocity.x *= -1;
			}

		}
		this->velocity.y *= -1.0f;
	}
	if (this->getPosition().y < 0) {
		this->soundWallBounce->play();
		this->velocity.y *= -1.0f;
	}

	if (this->getPosition().y > window->getSize().y - this->getGlobalBounds().height) {
		started = false;
		this->hp->MinusOne();
		this->soundLose->play();
	}

	if (this->getPosition().x < 0 || this->getPosition().x > window->getSize().x - this->getGlobalBounds().width) {
		this->soundWallBounce->play();
		//this->setPosition(window->getSize().x / 2 - 50, window->getSize().y / 2 - 30);
		this->velocity.x *= -1.0f;
	}

	Game_Object::Update();
	ballCenter = this->getPosition().x + this->getGlobalBounds().width / 2;
}
ball::~ball() {
	delete this->bufferBounce;
	delete this->bufferLose;
	delete this->bufferWallBounce;
	delete this->soundBounce;
	delete this->soundLose;
	delete this->soundWallBounce;
	delete this->soundBrick;
	delete this->bufferBrick;
	delete this->bk;
	delete this->P;
	delete this->bk1;
	delete this->bk2;
	delete this->bk3;
	delete this->bk4;
	delete this->bk5;
	delete this->bk6;
	delete this->bk7;
	delete this->bk8;
	delete this->bk9;
	delete this->bk10;
	delete this->bk11;
	delete this->bk12;
	delete this->bk13;
	delete this->bk14;
	delete this->bk15;
	delete this->bk16;
	delete this->bk17;
	delete this->bk18;
	delete this->bk19;
	delete this->bk20;
	delete this->bk21;
	delete this->bk22;
	delete this->bk23;
	delete this->bk24;
	delete this->bk25;
	delete this->bk26;
	delete this->bk27;
	delete this->bk28;
	delete this->bk29;
	delete this->bk30;
	delete this->bk31;
	delete this->bk32;
	delete this->bk33;
	delete this->bk34;
	delete this->bk35;
}