#pragma once
#include "Hero.h" 
#include "Obstacle.h"

class Batman :
    public Hero 
{
private:
     
    void addBomb( Board* FBoard);
     
    Obstacle* bomb;
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

