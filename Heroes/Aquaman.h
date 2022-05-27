#pragma once
#include "Hero.h"
class Aquaman :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    Aquaman(Board* FBoard);

    //Destruktor

    ~Aquaman();

    //Metody
    void skill();

    void update(const float& dt);
};

