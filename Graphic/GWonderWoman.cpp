#include "GWonderWoman.h"

GWonderWoman::GWonderWoman(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\WonderWoman.png");
	this->initFonts();
	/*this->collision.setSize(sf::Vector2f(26, 20));
	this->collision.setFillColor(sf::Color(255, 0, 0, 20));
	this->collision.setOutlineColor(sf::Color::Red);
	this->collision.setOrigin(sf::Vector2f(15,0));
	this->collision.setOutlineThickness(1.f);*/

	//this->circle.setFillColor(sf::Color(255, 0, 0, 50));
	//this->circle.setRadius(50);
	//this->circle.setOrigin(sf::Vector2f(50, 50));

	this->text.setString("WONDER_WOMAN");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(18, 33));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);

}

GWonderWoman::~GWonderWoman()
{
}

void GWonderWoman::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}