#include "GObject.h"

 
GObject::GObject(Object* object)
{
	this->object = object;
	health.setFillColor(sf::Color::Magenta);
	health.setSize(sf::Vector2f(2, 2));
}

GObject::~GObject()
{
}

 
sf::Sprite GObject::Graphic(std::string a )
{
	image.loadFromFile(a);
	image.createMaskFromColor(sf::Color(255, 255, 255)); 
	texture.loadFromImage(image);  
	sprite.setTexture(texture);

	sf::Vector2f targetSize(30.0f, 40.0f);
	sprite.setScale(targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width/2,
					 sprite.getLocalBounds().height/2));

	return sprite; 
}
 

//bool GObject::updateCollision(GObject* Gobj)
//{
//	sf::FloatRect HeroBounds = this->collision.getGlobalBounds();
//	sf::FloatRect OtherBounds = Gobj->collision.getGlobalBounds();
//	 
//	if (HeroBounds.left - 0.5 >= (OtherBounds.left + OtherBounds.width) ||
//		OtherBounds.left - 0.5 >= (HeroBounds.left + HeroBounds.width))
//	{
//		return false; 
//	}  
//
//	if (HeroBounds.top - 0.5 >= (OtherBounds.top + OtherBounds.height) ||
//		OtherBounds.top - 0.5 >= (HeroBounds.top + HeroBounds.height))
//	{
//		return false;
//	}
//	 
//	return true;
//} 
 
void GObject::update(const float& dt)
{
	rect.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X, 
								  object->getCoordinates().Coordinate_Y));
	 

	circle.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
								    object->getCoordinates().Coordinate_Y));

	health.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
									object->getCoordinates().Coordinate_Y));

	sprite.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
								    object->getCoordinates().Coordinate_Y));
}
