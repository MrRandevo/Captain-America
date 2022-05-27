#pragma once
#include "Button.h"
#include "Object.h"

class GObject
{
private:
	 
protected:
	sf::Texture texture;
	sf::Image image; 
	sf::Font font;
	sf::Text text;
	sf::RectangleShape rect;
	sf::Sprite sprite;

	//sf::RectangleShape collision;
	sf::CircleShape circle;
	  

	Object* object;


	void initFonts();
public: 
//Konstruktor
	GObject(Object * object); 
//Destruktor
	~GObject(); 

	sf::RectangleShape health;

//Metody:
	virtual void draw(sf::RenderTarget* target) = 0;
 
	sf::Sprite Graphic(std::string a );

	//bool updateCollision(GObject* Gobj);

	void update(const float& dt); 
};

