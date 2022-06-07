#include "State.h" 
#include "Button.h"


// Klasa odpowiada za stan Menu g��wnego programu

class MainMenu :
    public State
{
private:

 //Atrybuty:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Font font;

    //Kontener, ktory bedzie przechowywal wskazniki do obkietkow klasy Button
    std::map<std::string, Button*> buttons;

 //Metody:
    void initFonts(); 
    void initButtons();

public:
//Konstruktor: 
    MainMenu(sf::RenderWindow* window, std::stack <State*>* states);

//Destruktor:
    virtual ~MainMenu();

//Metody:
    //Aktualizacja stanu okna
    void update(const float& dt);

    //Wy�wietlanie okna
	void render(sf::RenderTarget* target = nullptr);

    //Aktualizacja stanu przyciskow
    void updateButtons();

    //Wyswietlanie przyciskow
    void renderButtons(sf::RenderTarget* target = nullptr);
    
};
