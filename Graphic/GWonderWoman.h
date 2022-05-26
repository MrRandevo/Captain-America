#pragma once
#include "GObject.h"
#include "WonderWoman.h"
class GWonderWoman :
    public GObject
{
private:
 
protected:

public:
    GWonderWoman(Object* object);

    ~GWonderWoman();

    void draw(sf::RenderTarget* target);

};

