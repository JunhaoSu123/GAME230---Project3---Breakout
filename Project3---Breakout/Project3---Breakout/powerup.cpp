#include"PowerUp.h"
#include"Ball.h"
powerup::powerup() {
	this->Load("power.png");
}
void powerup::Update(sf::RenderWindow* window) {

	Game_Object::Update();


}