#pragma once
#include "GObject.h"
#include "Aquaman.h"
class GAquaman :
    public GObject
{
private:

protected:

public:
    GAquaman(Object* object);

    ~GAquaman();

    void draw(sf::RenderTarget* target);
};

