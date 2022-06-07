#pragma once
#include "Hero.h"
#include "AStar.h"

class Joker :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    Joker(Board* FBoard);

    //Destruktor

    ~Joker();

    //Metody
    void skill();

    void update(const float& dt);
};

