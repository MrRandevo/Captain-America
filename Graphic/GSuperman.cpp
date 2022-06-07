#include "GSuperman.h"

GSuperman::GSuperman(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\Superman.png");
	this->initFonts(); 
	this->text.setString("SUPERMAN");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(14, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
}

GSuperman::~GSuperman()
{
}

void GSuperman::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}
