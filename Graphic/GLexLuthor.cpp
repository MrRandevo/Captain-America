#include "GLexLuthor.h"

GLexLuthor::GLexLuthor(Object* object)
	:GObject(object)
{
	this->sprite = Graphic("Sprite\\LexLuthor.png");
	this->initFonts();
	this->text.setString("LEX LUTHOR");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color(255, 0, 15));
	this->text.setOrigin(sf::Vector2f(16, 35));
	this->text.setCharacterSize(7);
	this->text.setStyle(sf::Text::Bold);
}

GLexLuthor::~GLexLuthor()
{
}

void GLexLuthor::draw(sf::RenderTarget* target)
{
	target->draw(sprite);
	target->draw(health);
	target->draw(text);
}
