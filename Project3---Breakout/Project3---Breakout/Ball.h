#pragma once
#include "player.h"
#include"Brick.h"
#include"Score.h"
#include"Life.h"
#include"PowerUp.h"
#include<SFML/Audio.hpp>

class ball : public Game_Object {
public:
	ball(player* P, 
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
	life* hp);
	void Update(sf::RenderWindow* window);
	~ball();
private:
	player* P;
	brick* bk;
	brick* bk1;
	brick* bk2;
	brick* bk3;
	brick* bk4;
	brick* bk5;
	brick* bk6;
	brick* bk7;
	brick* bk8;
	brick* bk9;
	brick* bk10;
	brick* bk11;
	brick* bk12;
	brick* bk13;
	brick* bk14;
	brick* bk15;
	brick* bk16;
	brick* bk17;
	brick* bk18;
	brick* bk19;
	brick* bk20;
	brick* bk21;
	brick* bk22;
	brick* bk23;
	brick* bk24;
	brick* bk25;
	brick* bk26;
	brick* bk27;
	brick* bk28;
	brick* bk29;
	brick* bk30;
	brick* bk31;
	brick* bk32;
	brick* bk33;
	brick* bk34;
	brick* bk35;
	score* sc;
	life* hp;
	sf::SoundBuffer* bufferBounce;
	sf::Sound* soundBounce;
	sf::SoundBuffer* bufferWallBounce;
	sf::Sound* soundWallBounce;
	sf::SoundBuffer* bufferLose;
	sf::Sound* soundLose;
	sf::SoundBuffer* bufferBrick;
	sf::Sound* soundBrick;
};
extern bool started;