#include "GWonderWoman.h"

GWonderWoman::GWonderWoman(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\WonderWoman.png");

	/*this->collision.setSize(sf::Vector2f(26, 20));
	this->collision.setFillColor(sf::Color(255, 0, 0, 20));
	this->collision.setOutlineColor(sf::Color::Red);
	this->collision.setOrigin(sf::Vector2f(15,0));
	this->collision.setOutlineThickness(1.f);*/

	this->circle.setFillColor(sf::Color(255, 0, 0, 50));
	this->circle.setRadius(50);
	this->circle.setOrigin(sf::Vector2f(50, 50));
}

GWonderWoman::~GWonderWoman()
{
}

void GWonderWoman::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(circle);
	//target->draw(collision);
}