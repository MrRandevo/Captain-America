#pragma once
#include "Hero.h"
#include "AStar.h"

class Deathstroke :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    Deathstroke(Board* FBoard);

    //Destruktor 
    ~Deathstroke();

    //Metody
    void skill();

    void update(const float& dt);
};

