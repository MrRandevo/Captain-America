#pragma once
#include "Hero.h"
#include "AStar.h"

class LexLuthor :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    LexLuthor(Board* FBoard);

    //Destruktor

    ~LexLuthor();

    //Metody
    void skill();

    void update(const float& dt);
};

