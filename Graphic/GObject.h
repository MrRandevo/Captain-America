#pragma once
#include "Button.h"
#include "Object.h"

class GObject
{
private:
	 
protected:
	sf::Texture texture;
	sf::Image image; 
	sf::RectangleShape rect;
	sf::Sprite sprite;

	//sf::RectangleShape collision;
	sf::CircleShape circle;
	sf::RectangleShape health; 

	Object* object;
public: 
//Konstruktor
	GObject(Object * object);

//Destruktor
	~GObject();

//Metody:
	virtual void draw(sf::RenderTarget* target) = 0;
 
	sf::Sprite Graphic(std::string a );

	//bool updateCollision(GObject* Gobj);

	void update(const float& dt); 
};

