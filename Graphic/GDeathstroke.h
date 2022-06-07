#pragma once
#include "GObject.h"
#include "Deathstroke.h"
class GDeathstroke :
    public GObject
{
private:
protected:

public:
    GDeathstroke(Object* object);

    ~GDeathstroke();

    void draw(sf::RenderTarget* target);

};
