#pragma once
#include "Hero.h"
class WonderWoman :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    WonderWoman(Board* FBoard);

    //Destruktor

    ~WonderWoman();

    //Metody
    void skill();


    void update(const float& dt);
};

