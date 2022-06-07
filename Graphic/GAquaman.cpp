#include "GAquaman.h"

GAquaman::GAquaman(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\Aquaman.png");
	this->initFonts();
	this->text.setString("AQUAMAN");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(12, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
}

GAquaman::~GAquaman()
{
}

void GAquaman::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}
