#include "GCaptainCold.h"

GCaptainCold::GCaptainCold(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\CaptainCold.png");
	this->initFonts();
	this->text.setString("CAPTAIN COLD");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(18, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
}

GCaptainCold::~GCaptainCold()
{
}

void GCaptainCold::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}
