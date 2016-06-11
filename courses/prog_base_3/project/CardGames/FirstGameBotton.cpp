#include "FirstGameBotton.h"
#include "21/Consts.h"

FirstGameBotton::FirstGameBotton()
{
    this->height = 97;
    this->width = 258;
    this->posX = 100;
    this->posY = 100;
    this->texture.loadFromFile("img/21.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool FirstGameBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
