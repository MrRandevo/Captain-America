#include "GPoisonIvy.h"

GPoisonIvy::GPoisonIvy(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\PoisonIvy.png");
	this->initFonts();
	this->text.setString("POISON IVY");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(16, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
}

GPoisonIvy::~GPoisonIvy()
{
}

void GPoisonIvy::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}
