#include "State.h"
 
#include "Button.h"

class MainMenu :
    public State
{
private:
 //Atrybuty:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Font font;
    //Zmienna przechowujaca wszystkie przyciski
    std::map<std::string, Button*> buttons;

 //Metody prywatne:
    void initFonts(); 
    void initButtons();

public:
//Konstruktor 
    MainMenu(sf::RenderWindow* window, std::stack <State*>* states);

//Destruktor
    virtual ~MainMenu();

//Metody
     
    void update(const float& dt);

	void render(sf::RenderTarget* target = nullptr);

    void updateButtons();

    void renderButtons(sf::RenderTarget* target = nullptr);
    
};
