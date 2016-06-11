#include "RevealBottonSeka.h"
#include "Consts.h"

RevealBottonSeka::RevealBottonSeka()
{
    this->height = 79;
    this->width = 120;
    this->posX = 300;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/reveal.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool RevealBottonSeka::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
