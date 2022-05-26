#pragma once
#include "Hero.h"
class Batman :
    public Hero 
{
private:

protected:
   
public:
    //Konstruktor
    Batman(Board* FBoard);

    //Destruktor

    ~Batman();

    //Metody
    void skill();
     
    void update(const float& dt) ;
};

