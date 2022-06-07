#pragma once
#include "Hero.h"
#include "AStar.h"

class Darkseid :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    Darkseid(Board* FBoard);

    //Destruktor

    ~Darkseid();

    //Metody
    void skill();

    void update(const float& dt);
};

