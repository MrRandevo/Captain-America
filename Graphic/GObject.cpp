#include "GObject.h"

 
void GObject::initFonts()
{ 
	if (!this->font.loadFromFile("Fonts\\arial.ttf"))
	{
			std::cout << "Could not load";
	} 
}

GObject::GObject(Object* object)
{
	this->object = object; 
	this->health.setSize(sf::Vector2f(25, 4));
	this->health.setOrigin(sf::Vector2f(10,23));
	 
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
  
void GObject::update(const float& dt)
{
	rect.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X, 
								  object->getCoordinates().Coordinate_Y)); 
	 

	health.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
									object->getCoordinates().Coordinate_Y));

	sprite.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
								    object->getCoordinates().Coordinate_Y));

	text.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
									object->getCoordinates().Coordinate_Y));
	float temp = object->getAttributes().health;
	health.setSize(sf::Vector2f(((temp/100.0) * 25), 4));
}
