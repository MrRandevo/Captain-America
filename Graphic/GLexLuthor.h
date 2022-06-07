#pragma once
#include "GObject.h"
#include "LexLuthor.h"
class GLexLuthor :
    public GObject
{
private:
protected:

public:
    GLexLuthor(Object* object);

    ~GLexLuthor();

    void draw(sf::RenderTarget* target);

};

