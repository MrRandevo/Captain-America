#pragma once
#include "Button.h"


enum Images_states { IMG_IDLE = 0,IMG_HOVER, IMG_ACTIVE };

class Images
{
private:
	short unsigned ImagesState;   
	bool lock_click;
public:
	sf::RectangleShape shape;

	//Konstruktor
	Images(float x, float y, float width, float height, 
		sf::Texture *texture);

	//Destruktor
	~Images();

	//Functions
	const bool isPressed();
	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos);
	void changeTexture(sf::Texture* texture);
	 
 
};

