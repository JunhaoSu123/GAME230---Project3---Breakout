#pragma once
#include "Game_State.h"
#include"Player.h"
#include"Ball.h"
//#include"Score.h"
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

};