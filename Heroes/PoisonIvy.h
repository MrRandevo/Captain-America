#pragma once
#include "Hero.h"
#include "AStar.h"

class PoisonIvy :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    PoisonIvy(Board* FBoard);

    //Destruktor 
    ~PoisonIvy();

    //Metody
    void skill();

    void update(const float& dt);
};