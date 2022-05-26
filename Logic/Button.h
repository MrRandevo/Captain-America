#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <iostream>
#include <ctime>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>

//Stany przycisku
// 
//  BTN_IDLE - Oznacza ze wskaznik myszki nie jest na przycisku
//  BTN_HOVER - Oznacza ze wskaznik myszki jest na przycisku
//	BTN_ACTIVE - Wcisnieto przycisk

enum button_states{BTN_IDLE = 0, BTN_HOVER , BTN_ACTIVE};

class Button
{
private: 
//Atrybuty 
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:

//Konstruktor
	Button(float x, float y, float width, float height, 
		sf::Font *font,std::string text, sf::Color idleColor,
		sf::Color hoverColor, sf::Color activeColor);

//Destruktor
	~Button();

//Metody
	const bool isPressed();
	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos);
};

