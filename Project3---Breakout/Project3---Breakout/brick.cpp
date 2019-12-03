#include"Brick.h"
#include"Ball.h"
brick::brick() {
	this->Load("brick.png");
}
void brick::Update(sf::RenderWindow* window) {
	Game_Object::Update();
}