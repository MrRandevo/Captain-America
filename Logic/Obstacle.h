#pragma once
#include "Object.h"
class Obstacle :
    public Object
{
private:

protected:
     
public:
    //Konstruktor
    Obstacle(float pos_x, float pos_y, Board* FBoard);

    //Destruktor
    ~Obstacle();

//Atrybuty:
    bool isDestroyed;
//Metody:
    void update(const float& dt) ;
     
};

