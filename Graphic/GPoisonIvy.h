#pragma once
#include "GObject.h"
#include "PoisonIvy.h"
class GPoisonIvy :
    public GObject
{
private:
protected:

public:
    GPoisonIvy(Object* object);

    ~GPoisonIvy();

    void draw(sf::RenderTarget* target);

};

