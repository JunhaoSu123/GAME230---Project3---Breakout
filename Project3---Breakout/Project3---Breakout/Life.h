#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class life : public sf::Text {
public:
	life(sf::Font &font, unsigned int size);
	void MinusOne();
	void Update();
	void hpCheck();
private:
	int health;
};
extern bool GameOver;