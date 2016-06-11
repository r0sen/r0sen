#include "FifthGameBotton.h"
#include "21/Consts.h"

FifthGameBotton::FifthGameBotton()
{
    this->height = 97;
    this->width = 258;
    this->posX = 500;
    this->posY = 230;
    this->texture.loadFromFile("img/9val.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool FifthGameBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
