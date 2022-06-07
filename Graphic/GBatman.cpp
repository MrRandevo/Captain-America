#include "GBatman.h"
#include "Game.h"

GBatman::GBatman(Object* object )
	:GObject(object)
{ 
	this->sprite = Graphic("Sprite\\Batman.png" );
	this->initFonts(); 
	this->text.setString("BATMAN");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(12, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
	/*this->createAnimationComponent(this->sprite, texture_sheet);*/ 
	/*this->animationComponent->addAnimation("RUN_RIGHT", 4000.f, 0, 0, 8, 0, 30, 40); */
	this->bomb_texture.loadFromFile("Sprite\\bomb.png");
	bomb_sprite.setTexture(bomb_texture);

	sf::Vector2f targetSize(20.0f, 20.0f);
	bomb_sprite.setScale(targetSize.x / bomb_sprite.getLocalBounds().width,
		targetSize.y / bomb_sprite.getLocalBounds().height);
	bomb_sprite.setOrigin(sf::Vector2f(bomb_sprite.getLocalBounds().width / 2,
		bomb_sprite.getLocalBounds().height / 2));

	bomb_sprite.setPosition(sf::Vector2f(-100, -100));
}

GBatman::~GBatman()
{
	
}

void GBatman::draw(sf::RenderTarget* target)
{ 
	target->draw(sprite); 
	target->draw(health);
	target->draw(text); 
	
	target->draw(bomb_sprite);
}

void GBatman::update(const float& dt)
{
	health.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
		object->getCoordinates().Coordinate_Y));

	sprite.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
		object->getCoordinates().Coordinate_Y));
	text.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
		object->getCoordinates().Coordinate_Y));

	float temp = object->getAttributes().health;
	health.setSize(sf::Vector2f(((temp / 100.0) * 25.0), 4.0));

	/*this->animationComponent->play("RUN_RIGHT", dt);*/

	sf::Vector2f targetSize(30.0f, 40.0f);
	sprite.setScale(targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2,
		sprite.getLocalBounds().height / 2));   

	if (object->skill_help == 1)
	{ 
		bomb_sprite.setPosition(sf::Vector2f(object->getCoordinates().Coordinate_X,
			object->getCoordinates().Coordinate_Y));
		object->skill_help = 0;
	}
	  
}

 
