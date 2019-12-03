#include <iostream>
#include"Main_Menu.h"
#include"Game_Play.h"
#include"Brick.h"
#include"Score.h"
#include"Life.h"
#include"Game_State.h"
#include"WinState.h"
//#include"PowerUp.h"

bool lvl1 = true;
bool lvl2 = false;
bool lvl3 = false;
int speed = 0;
bool getPU = true;
bool GameOver = false;
void game_play::Initialize(sf::RenderWindow* window) {
	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");

	this->bufferWin = new sf::SoundBuffer();
	this->bufferWin->loadFromFile("Sounds/you_win.wav");
	this->soundWin = new sf::Sound(*this->bufferWin);
	this->bufferGo = new sf::SoundBuffer();
	this->bufferGo->loadFromFile("Sounds/go.wav");
	this->soundGo = new sf::Sound(*this->bufferGo);

	this->sc = new score(*font, 24U);
	this->sc->setPosition(0, 8);

	this->pu = new powerup;
	this->pu->setScale(0.45f, 0.5f);
	this->pu->setPosition((this->pu->getGlobalBounds().width + 20) + 5, (this->pu->getGlobalBounds().height + 20) * 3 + 50);

	this->hp = new life(*font, 24U);
	this->hp->setPosition(window->getSize().x - this->hp->getGlobalBounds().width, 8);

	this->level1 = new sf::Text("Level - 1", *this->font, 32U);
	this->level1->setOrigin(this->level1->getGlobalBounds().width / 2, 0);
	this->level1->setPosition(window->getSize().x / 2, 3);
	this->level2 = new sf::Text("Level - 2", *this->font, 32U);
	this->level2->setOrigin(this->level2->getGlobalBounds().width / 2, 0);
	this->level2->setPosition(window->getSize().x / 2, 3);
	this->level3 = new sf::Text("Level - 3", *this->font, 32U);
	this->level3->setOrigin(this->level3->getGlobalBounds().width / 2, 0);
	this->level3->setPosition(window->getSize().x / 2, 3);

	this->bk = new brick;
	this->bk1 = new brick;
	this->bk2= new brick;
	this->bk3= new brick;
	this->bk4= new brick;
	this->bk5= new brick;
	this->bk6= new brick;
	this->bk7= new brick;
	this->bk8= new brick;
	this->bk9= new brick;
	this->bk10= new brick;
	this->bk11= new brick;
	this->bk12= new brick;
	this->bk13= new brick;
	this->bk14= new brick;
	this->bk15= new brick;
	this->bk16= new brick;
	this->bk17= new brick;
	this->bk18= new brick;
	this->bk19= new brick;
	this->bk20= new brick;
	this->bk21= new brick;
	this->bk22= new brick;
	this->bk23= new brick;
	this->bk24= new brick;
	this->bk25= new brick;
	this->bk26= new brick;
	this->bk27= new brick;
	this->bk28= new brick;
	this->bk29= new brick;
	this->bk30= new brick;
	this->bk31= new brick;
	this->bk32= new brick;
	this->bk33= new brick;
	this->bk34= new brick;
	this->bk35= new brick;

	this->bk->setScale(0.45f, 0.5f);
	this->bk->setPosition(5, 50);
	this->bk1->setScale(0.45f, 0.5f);
	this->bk1->setPosition((this->bk->getGlobalBounds().width + 20) + 5, 50);
	this->bk2->setScale(0.45f, 0.5f);
	this->bk2->setPosition((this->bk->getGlobalBounds().width + 20)*2 + 5, 50);
	this->bk3->setScale(0.45f, 0.5f);
	this->bk3->setPosition((this->bk->getGlobalBounds().width + 20)*3 + 5, 50);
	this->bk4->setScale(0.45f, 0.5f);
	this->bk4->setPosition((this->bk->getGlobalBounds().width + 20)*4 + 5, 50);
	this->bk5->setScale(0.45f, 0.5f);
	this->bk5->setPosition((this->bk->getGlobalBounds().width + 20)*5 + 5, 50);

	this->bk6->setScale(0.45f, 0.5f);
	this->bk6->setPosition(5, (this->bk->getGlobalBounds().height + 20)+50);
	this->bk7->setScale(0.45f, 0.5f);
	this->bk7->setPosition((this->bk->getGlobalBounds().width + 20) + 5, (this->bk->getGlobalBounds().height + 20) + 50);
	this->bk8->setScale(0.45f, 0.5f);
	this->bk8->setPosition((this->bk->getGlobalBounds().width + 20) * 2 + 5, (this->bk->getGlobalBounds().height + 20) + 50);
	this->bk9->setScale(0.45f, 0.5f);
	this->bk9->setPosition((this->bk->getGlobalBounds().width + 20) * 3 + 5, (this->bk->getGlobalBounds().height + 20) + 50);
	this->bk10->setScale(0.45f, 0.5f);
	this->bk10->setPosition((this->bk->getGlobalBounds().width + 20) * 4 + 5, (this->bk->getGlobalBounds().height + 20) + 50);
	this->bk11->setScale(0.45f, 0.5f);
	this->bk11->setPosition((this->bk->getGlobalBounds().width + 20) * 5 + 5, (this->bk->getGlobalBounds().height + 20) + 50);

	this->bk12->setScale(0.45f, 0.5f);
	this->bk12->setPosition(5, (this->bk->getGlobalBounds().height + 20)*2 + 50);
	this->bk13->setScale(0.45f, 0.5f);
	this->bk13->setPosition((this->bk->getGlobalBounds().width + 20) + 5, (this->bk->getGlobalBounds().height + 20) * 2 + 50);
	this->bk14->setScale(0.45f, 0.5f);
	this->bk14->setPosition((this->bk->getGlobalBounds().width + 20) * 2 + 5, (this->bk->getGlobalBounds().height + 20) * 2 + 50);
	this->bk15->setScale(0.45f, 0.5f);
	this->bk15->setPosition((this->bk->getGlobalBounds().width + 20) * 3 + 5, (this->bk->getGlobalBounds().height + 20) * 2 + 50);
	this->bk16->setScale(0.45f, 0.5f);
	this->bk16->setPosition((this->bk->getGlobalBounds().width + 20) * 4 + 5, (this->bk->getGlobalBounds().height + 20) * 2 + 50);
	this->bk17->setScale(0.45f, 0.5f);
	this->bk17->setPosition((this->bk->getGlobalBounds().width + 20) * 5 + 5, (this->bk->getGlobalBounds().height + 20) * 2 + 50);

	this->bk18->setScale(0.45f, 0.5f);
	this->bk18->setPosition(5, (this->bk->getGlobalBounds().height + 20) * 3 + 50);
	this->bk19->setScale(0.45f, 0.5f);
	this->bk19->setPosition((this->bk->getGlobalBounds().width + 20) + 5, (this->bk->getGlobalBounds().height + 20) * 3 + 50);
	this->bk20->setScale(0.45f, 0.5f);
	this->bk20->setPosition((this->bk->getGlobalBounds().width + 20) * 2 + 5, (this->bk->getGlobalBounds().height + 20) * 3 + 50);
	this->bk21->setScale(0.45f, 0.5f);
	this->bk21->setPosition((this->bk->getGlobalBounds().width + 20) * 3 + 5, (this->bk->getGlobalBounds().height + 20) * 3 + 50);
	this->bk22->setScale(0.45f, 0.5f);
	this->bk22->setPosition((this->bk->getGlobalBounds().width + 20) * 4 + 5, (this->bk->getGlobalBounds().height + 20) * 3 + 50);
	this->bk23->setScale(0.45f, 0.5f);
	this->bk23->setPosition((this->bk->getGlobalBounds().width + 20) * 5 + 5, (this->bk->getGlobalBounds().height + 20) * 3 + 50);

	this->bk24->setScale(0.45f, 0.5f);
	this->bk24->setPosition(5, (this->bk->getGlobalBounds().height + 20) * 4 + 50);
	this->bk25->setScale(0.45f, 0.5f);
	this->bk25->setPosition((this->bk->getGlobalBounds().width + 20) + 5, (this->bk->getGlobalBounds().height + 20) * 4 + 50);
	this->bk26->setScale(0.45f, 0.5f);
	this->bk26->setPosition((this->bk->getGlobalBounds().width + 20) * 2 + 5, (this->bk->getGlobalBounds().height + 20) * 4 + 50);
	this->bk27->setScale(0.45f, 0.5f);
	this->bk27->setPosition((this->bk->getGlobalBounds().width + 20) * 3 + 5, (this->bk->getGlobalBounds().height + 20) * 4 + 50);
	this->bk28->setScale(0.45f, 0.5f);
	this->bk28->setPosition((this->bk->getGlobalBounds().width + 20) * 4 + 5, (this->bk->getGlobalBounds().height + 20) * 4 + 50);
	this->bk29->setScale(0.45f, 0.5f);
	this->bk29->setPosition((this->bk->getGlobalBounds().width + 20) * 5 + 5, (this->bk->getGlobalBounds().height + 20) * 4 + 50);

	this->bk30->setScale(0.45f, 0.5f);
	this->bk30->setPosition(5, (this->bk->getGlobalBounds().height + 20) * 5 + 50);
	this->bk31->setScale(0.45f, 0.5f);
	this->bk31->setPosition((this->bk->getGlobalBounds().width + 20) + 5, (this->bk->getGlobalBounds().height + 20) * 5 + 50);
	this->bk32->setScale(0.45f, 0.5f);
	this->bk32->setPosition((this->bk->getGlobalBounds().width + 20) * 2 + 5, (this->bk->getGlobalBounds().height + 20) * 5 + 50);
	this->bk33->setScale(0.45f, 0.5f);
	this->bk33->setPosition((this->bk->getGlobalBounds().width + 20) * 3 + 5, (this->bk->getGlobalBounds().height + 20) * 5 + 50);
	this->bk34->setScale(0.45f, 0.5f);
	this->bk34->setPosition((this->bk->getGlobalBounds().width + 20) * 4 + 5, (this->bk->getGlobalBounds().height + 20) * 5 + 50);
	this->bk35->setScale(0.45f, 0.5f);
	this->bk35->setPosition((this->bk->getGlobalBounds().width + 20) * 5 + 5, (this->bk->getGlobalBounds().height + 20) * 5 + 50);
	

	this->P = new player;
	this->P->setPosition(window->getSize().x /2 - this->P->getGlobalBounds().width/2, window->getSize().y-40);

	this->ballObject = new ball(this->P, 
		this->bk, 
		this->bk1,
		this->bk2,
		this->bk3,
		this->bk4,
		this->bk5,
		this->bk6,
		this->bk7,
		this->bk8,
		this->bk9,
		this->bk10,
		this->bk11,
		this->bk12,
		this->bk13,
		this->bk14,
		this->bk15,
		this->bk16,
		this->bk17,
		this->bk18,
		this->bk19,
		this->bk20,
		this->bk21,
		this->bk22,
		this->bk23,
		this->bk24,
		this->bk25,
		this->bk26,
		this->bk27,
		this->bk28,
		this->bk29,
		this->bk30,
		this->bk31,
		this->bk32,
		this->bk33,
		this->bk34,
		this->bk35,
		this->sc,
		this->hp);
	this->ballObject->setScale(0.5f, 0.5f);
	this->ballObject->setPosition(this->P->getPosition().x + this->P->getGlobalBounds().width / 2, window->getSize().y - 45 - this->P->getGlobalBounds().height);

}
void game_play::Update(sf::RenderWindow* window) {

	this->P->Update();
	this->ballObject->Update(window);
	this->sc->Update();
	this->hp->Update();
	this->hp->hpCheck();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		started = true;
		this->soundGo->play();
	}
	if (GameOver) {
		coreState.SetState(new win_state());
		GameOver = false;
		started = false;
		getPU = true;
		speed = 0;
		ballS = 0;
		lvl1 = true;
		lvl2 = false;
		lvl3 = false;
		brk = true;
		brk1 = true;
		brk2 = true;
		brk3 = true;
		brk4 = true;
		brk5 = true;
		brk6 = true;
		brk7 = true;
		brk8 = true;
		brk9 = true;
		brk10 = true;
		brk11 = true;
		brk12 = true;
		brk13 = true;
		brk14 = true;
		brk15 = true;
		brk16 = true;
		brk17 = true;
		brk18 = true;
		brk19 = true;
		brk20 = true;
		brk21 = true;
		brk22 = true;
		brk23 = true;
		brk24 = true;
		brk25 = true;
		brk26 = true;
		brk27 = true;
		brk28 = true;
		brk29 = true;
		brk30 = true;
		brk31 = true;
		brk32 = true;
		brk33 = true;
		brk34 = true;
		brk35 = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new main_menu());
		started = false;
		getPU = true;
		speed = 0;
		ballS = 0;
		lvl1 = true;
		lvl2 = false;
		lvl3 = false;
		brk = true;
		brk1 = true;
		brk2 = true;
		brk3 = true;
		brk4 = true;
		brk5 = true;
		brk6 = true;
		brk7 = true;
		brk8 = true;
		brk9 = true;
		brk10 = true;
		brk11 = true;
		brk12 = true;
		brk13 = true;
		brk14 = true;
		brk15 = true;
		brk16 = true;
		brk17 = true;
		brk18 = true;
		brk19 = true;
		brk20 = true;
		brk21 = true;
		brk22 = true;
		brk23 = true;
		brk24 = true;
		brk25 = true;
		brk26 = true;
		brk27 = true;
		brk28 = true;
		brk29 = true;
		brk30 = true;
		brk31 = true;
		brk32 = true;
		brk33 = true;
		brk34 = true;
		brk35 = true;
	}
	//Level1 //////////////////////////////////////////////
	if (lvl1 == true &&
		lvl2 == false &&
		lvl3 == false &&
		brk == false &&
		brk1 == false &&
		brk2 == false &&
		brk3 == false &&
		brk4 == false &&
		brk5 == false &&
		brk6 == false &&
		brk7 == false &&
		brk8 == false &&
		brk9 == false &&
		brk10 == false &&
		brk11 == false &&
		brk12 == false &&
		brk13 == false &&
		brk14 == false &&
		brk15 == false &&
		brk16 == false &&
		brk17 == false &&
		brk18 == false &&
		brk19 == false &&
		brk20 == false &&
		brk21 == false &&
		brk22 == false &&
		brk23 == false &&
		brk24 == false &&
		brk25 == false &&
		brk26 == false &&
		brk27 == false &&
		brk28 == false &&
		brk29 == false &&
		brk30 == false &&
		brk31 == false &&
		brk32 == false &&
		brk33 == false &&
		brk34 == false &&
		brk35 == false) {
		this->soundWin->play();
		speed += 1;
		started = false;
		lvl1 = false;
		lvl2 = true;
		lvl3 = false;
		brk = true;
		brk1 = true;
		brk2 = true;
		brk3 = true;
		brk4 = true;
		brk5 = true;
		brk6 = true;
		brk7 = true;
		brk8 = true;
		brk9 = true;
		brk10 = true;
		brk11 = true;
		brk12 = true;
		brk13 = true;
		brk14 = false;
		brk15 = false;
		brk16 = true;
		brk17 = true;
		brk18 = false;
		brk19 = true;
		brk20 = false;
		brk21 = false;
		brk22 = true;
		brk23 = false;
		brk24 = false;
		brk25 = true;
		brk26 = true;
		brk27 = true;
		brk28 = true;
		brk29 = false;
		brk30 = false;
		brk31 = false;
		brk32 = true;
		brk33 = true;
		brk34 = false;
		brk35 = false;
	}
	//Level2//////////////////////////////////////////
	if (lvl1 == false &&
		lvl2 == true &&
		lvl3 == false &&
		brk == false &&
		brk1 == false &&
		brk2 == false &&
		brk3 == false &&
		brk4 == false &&
		brk5 == false &&
		brk6 == false &&
		brk7 == false &&
		brk8 == false &&
		brk9 == false &&
		brk10 == false &&
		brk11 == false &&
		brk12 == false &&
		brk13 == false &&
		brk14 == false &&
		brk15 == false &&
		brk16 == false &&
		brk17 == false &&
		brk18 == false &&
		brk19 == false &&
		brk20 == false &&
		brk21 == false &&
		brk22 == false &&
		brk23 == false &&
		brk24 == false &&
		brk25 == false &&
		brk26 == false &&
		brk27 == false &&
		brk28 == false &&
		brk29 == false &&
		brk30 == false &&
		brk31 == false &&
		brk32 == false &&
		brk33 == false &&
		brk34 == false &&
		brk35 == false) {
		this->soundWin->play();
		speed += 1;
		started = false;
		lvl1 = false;
		lvl2 = false;
		lvl3 = true;
		brk = false;
		brk1 = true;
		brk2 = false;
		brk3 = false;
		brk4 = true;
		brk5 = false;
		brk6 = false;
		brk7 = true;
		brk8 = false;
		brk9 = false;
		brk10 = true;
		brk11 = false;
		brk12 = true;
		brk13 = true;
		brk14 = true;
		brk15 = true;
		brk16 = true;
		brk17 = true;
		brk18 = true;
		brk19 = true;
		brk20 = true;
		brk21 = true;
		brk22 = true;
		brk23 = true;
		brk24 = false;
		brk25 = true;
		brk26 = false;
		brk27 = false;
		brk28 = true;
		brk29 = false;
		brk30 = false;
		brk31 = true;
		brk32 = false;
		brk33 = false;
		brk34 = true;
		brk35 = false;
	}
	//Level3/////////////////////////////
	if (lvl1 == false &&
		lvl2 == false &&
		lvl3 == true &&
		brk == false &&
		brk1 == false &&
		brk2 == false &&
		brk3 == false &&
		brk4 == false &&
		brk5 == false &&
		brk6 == false &&
		brk7 == false &&
		brk8 == false &&
		brk9 == false &&
		brk10 == false &&
		brk11 == false &&
		brk12 == false &&
		brk13 == false &&
		brk14 == false &&
		brk15 == false &&
		brk16 == false &&
		brk17 == false &&
		brk18 == false &&
		brk19 == false &&
		brk20 == false &&
		brk21 == false &&
		brk22 == false &&
		brk23 == false &&
		brk24 == false &&
		brk25 == false &&
		brk26 == false &&
		brk27 == false &&
		brk28 == false &&
		brk29 == false &&
		brk30 == false &&
		brk31 == false &&
		brk32 == false &&
		brk33 == false &&
		brk34 == false &&
		brk35 == false) {
		this->soundWin->play();
		speed += 1;
		started = false;
		lvl1 = true;
		lvl2 = false;
		lvl3 = false;
		brk = true;
		brk1 = true;
		brk2 = true;
		brk3 = true;
		brk4 = true;
		brk5 = true;
		brk6 = true;
		brk7 = true;
		brk8 = true;
		brk9 = true;
		brk10 = true;
		brk11 = true;
		brk12 = true;
		brk13 = true;
		brk14 = true;
		brk15 = true;
		brk16 = true;
		brk17 = true;
		brk18 = true;
		brk19 = true;
		brk20 = true;
		brk21 = true;
		brk22 = true;
		brk23 = true;
		brk24 = true;
		brk25 = true;
		brk26 = true;
		brk27 = true;
		brk28 = true;
		brk29 = true;
		brk30 = true;
		brk31 = true;
		brk32 = true;
		brk33 = true;
		brk34 = true;
		brk35 = true;
	}
}
void game_play::Render(sf::RenderWindow* window) {
	if (getPU == false) {
		this->P->setScale(0.7f, 0.45f);
	}
	else if (getPU == true) {
		this->P->setScale(0.5f, 0.45f);
	}
	window->draw(*this->P);
	window->draw(*this->sc);
	window->draw(*this->ballObject);
	if(brk){window->draw(*this->bk);}
	if(brk1){window->draw(*this->bk1);}
	if(brk2){window->draw(*this->bk2);}
	if(brk3){window->draw(*this->bk3);}
	if(brk4){window->draw(*this->bk4);}
	if(brk5){window->draw(*this->bk5);}
	if(brk6){window->draw(*this->bk6);}
	if(brk7){window->draw(*this->bk7);}
	if(brk8){window->draw(*this->bk8);}
	if(brk9){window->draw(*this->bk9);}
	if(brk10){window->draw(*this->bk10);}
	if(brk11){window->draw(*this->bk11);}
	if(brk12){window->draw(*this->bk12);}
	if(brk13){window->draw(*this->bk13);}
	if(brk14){window->draw(*this->bk14);}
	if(brk15){window->draw(*this->bk15);}
	if(brk16){window->draw(*this->bk16);}
	if(brk17){window->draw(*this->bk17);}
	if(brk18){window->draw(*this->bk18);}
	if(brk19){window->draw(*this->bk19);}
	if(brk20){window->draw(*this->bk20);}
	if(brk21){window->draw(*this->bk21);}
	if(brk22){window->draw(*this->bk22);}
	if(brk23){window->draw(*this->bk23);}
	if(brk24){window->draw(*this->bk24);}
	if(brk25){window->draw(*this->bk25);}
	if(brk26){window->draw(*this->bk26);}
	if(brk27){window->draw(*this->bk27);}
	if(brk28){window->draw(*this->bk28);}
	if(brk29){window->draw(*this->bk29);}
	if(brk30){window->draw(*this->bk30);}
	if(brk31){window->draw(*this->bk31);}
	if(brk32){window->draw(*this->bk32);}
	if(brk33){window->draw(*this->bk33);}
	if(brk34){window->draw(*this->bk34);}
	if(brk35){window->draw(*this->bk35);}

	this->level1->setFillColor(sf::Color::Green);
	this->level2->setFillColor(sf::Color::Green);
	this->level3->setFillColor(sf::Color::Green);
	if (lvl1) {
		window->draw(*this->level1);
	}
	if (lvl2) {
		window->draw(*this->level2);
	}
	if (lvl3) {
		window->draw(*this->level3);
	}
	window->draw(*this->hp);
	if (getPU) {
		window->draw(*this->pu);
	}
}
void game_play::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->ballObject;
	delete this->sc;
	delete this->level1;
	delete this->level2;
	delete this->level3;
	delete this->hp;
	delete this->soundWin;
	delete this->bufferWin;
	delete this->bufferGo;
	delete this->soundGo;
}
