#pragma once 
#include "Object.h"
#include "Hero.h"

class State
{
protected:

//Atrybuty:
	sf::RenderWindow* window;
	std::stack <State*>* states;
	static std::vector<std::string> name; 

	//Polozonie myszki
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	 
	//Opuszczenie programu
	bool quit;

public:

//Konstruktor
	State(sf::RenderWindow* window, std::stack <State*>* states);

//Destruktor
	virtual ~State();

//Atrybuty:
	//zmienna do sprawdzania czy uzytkownik chce opuscic program
	const bool& getQuit() const; 

//Metody:  

	//Aktualizacja pozycji myszki
	virtual void updateMousePosition();
  				 
	//Deklaracja w podklasie, aktualizacja ekranu
	virtual void update(const float& dt) = 0;
 
	//Deklaracja w podklasie, drukowanie ekranu
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
												
	 
};