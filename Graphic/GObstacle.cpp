#include "GObstacle.h"

GObstacle::GObstacle(Object* object, sf::Texture *texture)
	: GObject(object)
{
	 
	this->rect.setSize(sf::Vector2f(50, 50));
	this->rect.setPosition(object->getCoordinates().Coordinate_X,
						   object->getCoordinates().Coordinate_Y);
	this->rect.setTexture(texture); 
	this->rect.setOrigin(sf::Vector2f(25, 25));

	/*this->collision.setSize(sf::Vector2f(50,50));
	this->collision.setFillColor(sf::Color(0, 255, 0, 20));
	this->collision.setOutlineColor(sf::Color::Magenta);
	this->collision.setOutlineThickness(1.f); 
	this->collision.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
									         object->getCoordinates().Coordinate_Y));
	this->collision.setOrigin(sf::Vector2f(25, 25));*/
}

GObstacle::~GObstacle()
{

}

void GObstacle::draw(sf::RenderTarget* target)
{
	//target->draw(collision);
	target->draw(rect); 
}
