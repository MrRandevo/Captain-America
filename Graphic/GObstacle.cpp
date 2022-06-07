#include "GObstacle.h"

GObstacle::GObstacle(Object* object, sf::Texture *texture)
	: GObject(object)
{
	 
	this->rect.setSize(sf::Vector2f(50, 50));
	this->rect.setPosition(object->getCoordinates().Coordinate_X,
						   object->getCoordinates().Coordinate_Y);
	this->rect.setTexture(texture); 
	this->rect.setOrigin(sf::Vector2f(25, 25));
	 
}

GObstacle::~GObstacle()
{

}

void GObstacle::draw(sf::RenderTarget* target)
{
	target->draw(rect); 
}
