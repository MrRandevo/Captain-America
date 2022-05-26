#pragma once
#include "Hero.h"
class Superman :
    public Hero
{
private:

protected:

public:
    //Konstruktor
    Superman(Board* FBoard);

    //Destruktor

    ~Superman();

    //Metody
    void skill();
     
    void update(const float& dt);
};

