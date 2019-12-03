#pragma once
#include "Game_State.h"
#include"Player.h"
#include"Ball.h"
#include"Brick.h"
#include"Score.h"
#include"Life.h"
#include<SFML/Audio.hpp>
//#include"PowerUp.h"

class game_play : public tiny_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	player* P;
	ball* ballObject;
	sf::Font* font;
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
	powerup* pu;
	sf::Text* level1;
	sf::Text* level2;
	sf::Text* level3;
	sf::SoundBuffer* bufferWin;
	sf::Sound* soundWin;
	sf::SoundBuffer* bufferGo;
	sf::Sound* soundGo;
};