#include "GHeal.h"

GHeal::GHeal(Object* object, sf::Texture* texture)
	:GObject(object)
{
	this->rect.setSize(sf::Vector2f(40, 40));
	this->rect.setPosition(object->getCoordinates().Coordinate_X,
		object->getCoordinates().Coordinate_Y);
	this->rect.setTexture(texture);
	this->rect.setOrigin(sf::Vector2f(20, 20));
}

GHeal::~GHeal()
{
}

void GHeal::draw(sf::RenderTarget* target)
{
	target->draw(rect);
}
