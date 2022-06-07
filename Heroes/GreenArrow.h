#pragma once
#include "Hero.h"
class GreenArrow :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    GreenArrow(Board* FBoard);

    //Destruktor 
    ~GreenArrow();

    //Metody
    void skill();

    void update(const float& dt);
};

