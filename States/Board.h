#pragma once

class Object;

#include "State.h"
#include "GObject.h"
#include "GBatman.h"
#include "GSuperman.h"
#include "TileMap.h"
#include "GObstacle.h"
#include "GWonderWoman.h"

class Board :
    public State
{
private:
//Atrybuty:
    sf::Font font; 
     
     

//Metody:
    void initFonts();
    void initHeroes();

protected:
 
public:
//Konstruktor 
    Board(sf::RenderWindow* window, std::stack <State*>* states);

//Destruktor
    virtual ~Board();

//Atrybuty:
    std::vector<GObject*> GObjects;
    std::vector<Object*> Objects;
    TileMap* Map;
//Metody:
    void update(const float& dt);
 
    void render(sf::RenderTarget* target = nullptr);
    
    void updateHeroes(const float& dt);

    void renderHeroes(sf::RenderTarget* target = nullptr);

    void updateMap(const float& dt);
};

