#pragma once 
#include "Object.h"
#include "Hero.h"

// Klasa abstrakcyjna, która odpowiada za wyswietlanie tresci
// oraz ulatwi przemieszczanie sie pomiedzy stanami graficznymi

class State
{
protected:

//Atrybuty:
	sf::RenderWindow* window;
	std::stack <State*>* states;

	//Statyczny atrybut, zawieraj¹cy dodanych bohaterow do planszy
	static std::vector<std::string> name; 

	//Polozonie myszki
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	 
	//Opuszczenie programu
	bool quit;

public:

//Konstruktor:
	State(sf::RenderWindow* window, std::stack <State*>* states);

//Destruktor:
	virtual ~State();

//Atrybuty:
	 

//Metody:  

	// S³uzy do sprawdzania stanu zmiennej bool
	const bool& getQuit() const;

	//Aktualizacja pozycji myszki
	virtual void updateMousePosition();
  				 
	//Deklaracja w podklasie, aktualizacja ekranu
	virtual void update(const float& dt) = 0;
 
	//Deklaracja w podklasie, drukowanie ekranu
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
												
	 
};