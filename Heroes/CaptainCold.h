#pragma once
#include "Hero.h"
#include "AStar.h"

class CaptainCold :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    CaptainCold(Board* FBoard);

    //Destruktor

    ~CaptainCold();

    //Metody
    void skill();

    void update(const float& dt);
};

