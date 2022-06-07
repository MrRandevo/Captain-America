#include "GWonderWoman.h"

GWonderWoman::GWonderWoman(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\WonderWoman.png");
	this->initFonts(); 

	this->text.setString("WONDER WOMAN");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(20, 35));
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