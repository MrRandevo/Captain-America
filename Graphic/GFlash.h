#pragma once
#include "GObject.h"
#include "Flash.h"
class GFlash :
    public GObject
{
private:

protected:

public:
    GFlash(Object* object);

    ~GFlash();

    void draw(sf::RenderTarget* target);
};

