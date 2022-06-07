#include "GGreenArrow.h"

GGreenArrow::GGreenArrow(Object* object )
	:GObject(object)
{ 
	this->sprite = Graphic("Sprite\\GreenArrow.png");
	this->initFonts();
	this->text.setString("GREEN ARROW");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(17, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);

	/*this->createAnimationComponent(this->sprite,texture_sheet);*/

	/*sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2,
		sprite.getLocalBounds().height / 2));*/

	/*this->animationComponent->addAnimation("RUN_RIGHT", 600.f, 0, 1, 10, 0, 30, 43 );*/

}

GGreenArrow::~GGreenArrow()
{
}

void GGreenArrow::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}

void GGreenArrow::update(const float& dt)
{ 
	health.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
		object->getCoordinates().Coordinate_Y));

	sprite.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
		object->getCoordinates().Coordinate_Y)); 
	text.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
		object->getCoordinates().Coordinate_Y)); 
	 
	float temp = object->getAttributes().health;
	health.setSize(sf::Vector2f(((temp / 100.0) * 25), 4));

	/*this->animationComponent->play("RUN_RIGHT", dt);*/

	sf::Vector2f targetSize(30.0f, 40.0f);
	sprite.setScale(targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2,
		sprite.getLocalBounds().height / 2));

}
