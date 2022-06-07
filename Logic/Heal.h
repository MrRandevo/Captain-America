#pragma once
#include "Object.h"
class Heal :
    public Object
{
private:
    float heal; 
public:

    Heal(float pos_x, float pos_y, Board* FBoard);

    ~Heal();

    void increaseHealth(Object* object);

    void update(const float& dt);

};

