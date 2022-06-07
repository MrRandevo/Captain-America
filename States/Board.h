#pragma once

class Object;
#include "State.h"
#include "GObject.h"
#include "GBatman.h"
#include "GSuperman.h"
#include "GWonderWoman.h"
#include "GAquaman.h"
#include "GFlash.h"
#include "GGreenArrow.h"
#include "GDarkseid.h"
#include "GCaptainCold.h"
#include "GDeathstroke.h"
#include "GJoker.h"
#include "GLexLuthor.h"
#include "GPoisonIvy.h"
#include "TileMap.h"
#include "GObstacle.h"
 
class Board :
    public State
{
private:
//Atrybuty:
    sf::Font font; 
     
//Metody:
    void initFonts();
    //void initTextures();
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
    std::map<std::string, sf::Texture*> Textures;

//Metody:
    void update(const float& dt);
 
    void render(sf::RenderTarget* target = nullptr);
    
    void updateHeroes(const float& dt);

    void renderHeroes(sf::RenderTarget* target = nullptr);

    void updateMap(const float& dt);

    void checkForEnd();
};

