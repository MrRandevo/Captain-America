#pragma once
#include "Hero.h"
class Flash :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    Flash(Board* FBoard);

    //Destruktor 
    ~Flash();

    //Metody
    void skill();

    void update(const float& dt);
};

