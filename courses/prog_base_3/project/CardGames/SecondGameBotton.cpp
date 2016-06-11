#include "SecondGameBotton.h"
#include "21/Consts.h"

SecondGameBotton::SecondGameBotton()
{
    this->height = 97;
    this->width = 258;
    this->posX = 100;
    this->posY = 230;
    this->texture.loadFromFile("img/seka.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool SecondGameBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
