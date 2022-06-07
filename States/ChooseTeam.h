#pragma once
#include "State.h"  
#include "Images.h"

// Klasa odpowiada za stan Wybor bohaterow programu
class ChooseTeam :
    public State
{
private:

//Atrybuty:
    sf::Font font;
    sf::Texture *texture;
    sf::Text text1, text2, text3, text4;
 
    //Kontenery przechowujace wskazniki do roznych obiektow
    std::map<std::string, sf::Texture*> Textures;
    std::map<std::string, Button*> buttons;
    std::map<std::string, Images*> imags; 
   
//Metody:     
    //Metody wywo³ywane przy inicjalizacji obiektu
    void initFonts();
    void initButtons();
    void initImages();
    void initText();
    void initTextures();
     
public:

//Konstruktor
    ChooseTeam(sf::RenderWindow* window, std::stack <State*>* states);

//Destruktor
    virtual ~ChooseTeam();

//Metody:
    //Wyœwietlanie okna
	void render(sf::RenderTarget* target = nullptr) ;

    //Aktualizacja stanu okna
	void update(const float& dt) ;

    //Wyswietlenie tekstu
    void renderText(sf::RenderTarget* target = nullptr);

    //Wyswietlanie przyciskow
    void renderButtons(sf::RenderTarget* target = nullptr);

    //Aktualizacja stanu przyciskow
    void updateButtons();
     
    //Wyswietlenie obrazow
    void renderImages(sf::RenderTarget* target = nullptr);

    //Aktualizacja stanu obrazow
    void updateImages();
 
};

