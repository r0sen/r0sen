#include "FourthGameBotton.h"
#include "21/Consts.h"

FourthGameBotton::FourthGameBotton()
{
    this->height = 97;
    this->width = 258;
    this->posX = 500;
    this->posY = 100;
    this->texture.loadFromFile("img/100.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool FourthGameBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
