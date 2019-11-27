#pragma once
#include "player.h"
#include<SFML/Audio.hpp>

class ball : public Game_Object {
public:
	ball(player* P);
	void Update(sf::RenderWindow* window);
	~ball();
private:
	player* P;

	sf::SoundBuffer* bufferBounce;
	sf::Sound* soundBounce;
};