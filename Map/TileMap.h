#pragma once
class Board;
#include "GObject.h"
#include "GObstacle.h"

 
class TileMap 
    
{ 
private:
//Atrybuty:
    std::vector<std::vector<sf::RectangleShape>> map;
    std::map<std::string, sf::Texture*> Textures;
     
     
    int maxSize_x, maxSize_y;
    float gridSize;
    int* counter;

//Metody:
    void initTextures();
    void initObjects();

protected:
     
public:
//Konstruktor
    TileMap(Board* FBoard);
//Destruktor
    ~TileMap();

//Atrybuty:
    Board * FBoard;
    std::vector<GObject*> Gobj;
    std::vector<Object*> Obj;
//Metody:
    void render(sf::RenderTarget* target);   
    void update(const float& dt);
};