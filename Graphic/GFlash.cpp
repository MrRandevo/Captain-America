#include "GFlash.h"

GFlash::GFlash(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\Flash.png");
	this->initFonts();
	this->text.setString("FLASH");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(12, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
}

GFlash::~GFlash()
{
}

void GFlash::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}
