#pragma once
#include "GObject.h"
#include "Superman.h"
class GSuperman :
    public GObject
{
private:  
protected:

public:
    GSuperman(Object* object);

    ~GSuperman();

    void draw(sf::RenderTarget* target);

};

