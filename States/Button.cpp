#include "Button.h"

//Konstruktor
Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, sf::Color idleColor,
	sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition( this->shape.getPosition().x + (this->shape.getSize().x /2.f) - this->text.getGlobalBounds().width /2.f ,
						    this->shape.getPosition().y + (this->shape.getSize().y /2.f) - this->text.getGlobalBounds().height  
						   );
	
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->shape.setFillColor(idleColor); 
}

//Destruktor
Button::~Button()
{
}

//Czy przycisk jest wcisniety?
const bool Button::isPressed()
{
	if (buttonState == BTN_ACTIVE)
		return true;
	
	return false;
}

//Drukuj ksztalt przycisku i tekst
void Button::render(sf::RenderTarget* target)
{
	 target->draw(this->shape);
	 target->draw(this->text);
}

//Aktualizacja stanu przycisku (Czy myszka znajduje sie na przycisku)
void Button::update(sf::Vector2f mousePos)
{
	if (shape.getGlobalBounds().contains(mousePos))
	{
		buttonState = BTN_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)  )
		{
			buttonState = BTN_ACTIVE; 
		} 
	}

	else
	{
		buttonState = BTN_IDLE;
	}

	switch (buttonState)
	{
	case BTN_IDLE:
		shape.setFillColor(idleColor);
		break;
	case BTN_HOVER:
		shape.setFillColor(hoverColor);
		break;
	case BTN_ACTIVE:
		shape.setFillColor(activeColor);
		break;

	default:
		shape.setFillColor(sf::Color::Red);
		break;
	}

}

 