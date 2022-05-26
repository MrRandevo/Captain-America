#include "Images.h"

Images::Images(float x, float y, float width, float height, 
	sf::Texture* texture)
{

	this->ImagesState = IMG_IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height)); 
	this->shape.setTexture(texture);
	this->shape.setOutlineThickness(3);
	this->shape.setOutlineColor(sf::Color(244, 213, 123));
}
 
Images::~Images()
{
}

const bool Images::isPressed()
{
	if (ImagesState == IMG_ACTIVE)
		return true;

	return false;
}

void Images::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Images::update(sf::Vector2f mousePos)
{
	if (shape.getGlobalBounds().contains(mousePos))
	{
		ImagesState = IMG_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && lock_click!=true)
		{
			ImagesState = IMG_ACTIVE;
			std::cout << "Wcisnieto";
			lock_click = true;

			
		}
		
	}
	else
	{
		ImagesState = BTN_IDLE;
		lock_click = false;
	}
}

void Images::changeTexture(sf::Texture* texture)
{
	this->shape.setTexture(texture);
}

 