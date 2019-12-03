#pragma once
#include "Game_State.h"
#include<SFML/Audio.hpp>
#include"Score.h"

class win_state : public tiny_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	sf::Font* font;
	sf::Text* gameOver;
	sf::Text* esc;
	sf::SoundBuffer* bufferLose;
	sf::Sound* soundLose;
};