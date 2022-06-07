#pragma once
#include "GObject.h"
#include "Darkseid.h"

class GDarkseid :
    public GObject
{
private:
protected:

public:
    GDarkseid(Object* object);

    ~GDarkseid();

    void draw(sf::RenderTarget* target);

};

