#include "GSuperman.h"

GSuperman::GSuperman(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\Superman.png");

	/*this->collision.setSize(sf::Vector2f(26, 20));
	this->collision.setFillColor(sf::Color(255, 0, 0, 20));
	this->collision.setOutlineColor(sf::Color::Red);
	this->collision.setOutlineThickness(1.f);
	this->collision.setOrigin(sf::Vector2f(15, 0));*/
	this->circle.setFillColor(sf::Color(255, 0, 0, 50));
	this->circle.setRadius(50);
	this->circle.setOrigin(sf::Vector2f(50,50));
}

GSuperman::~GSuperman()
{
}

void GSuperman::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(circle);
	//target->draw(collision);
}
