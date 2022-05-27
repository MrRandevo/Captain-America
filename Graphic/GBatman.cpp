#include "GBatman.h"
#include "Game.h"

GBatman::GBatman(Object* object)
	:GObject(object)
{ 
	this->sprite = Graphic("Sprite\\Batman.png" );
	this->initFonts(); 
	this->text.setString("BATMAN");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(12, 33));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
}

GBatman::~GBatman()
{
	
}

void GBatman::draw(sf::RenderTarget* target)
{ 
	target->draw(sprite); 
	target->draw(health);
	target->draw(text); 
}

 
