#pragma once
#include "State.h"
 
#include "Images.h"

class ChooseTeam :
    public State
{
private:
//Atrybuty:
    sf::Font font;
    sf::Texture *texture;
    sf::Text text1, text2, text3, text4;
 
    std::map<std::string, sf::Texture*> Textures;
    std::map<std::string, Button*> buttons;
    std::map<std::string, Images*> imags; 
   
//Metody:     
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
	void render(sf::RenderTarget* target = nullptr) ;

	void update(const float& dt) ;
 
    void renderText(sf::RenderTarget* target = nullptr);

    void renderButtons(sf::RenderTarget* target = nullptr);

    void updateButtons();
     
    void renderImages(sf::RenderTarget* target = nullptr);

    void updateImages();
 
};

