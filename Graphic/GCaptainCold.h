#pragma once
#include "GObject.h" 
#include "CaptainCold.h"
class GCaptainCold :
    public GObject
{
private:
protected:

public:
    GCaptainCold(Object* object);

    ~GCaptainCold();

    void draw(sf::RenderTarget* target);

};
