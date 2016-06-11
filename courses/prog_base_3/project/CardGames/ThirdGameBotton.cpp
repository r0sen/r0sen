#include "ThirdGameBotton.h"
#include "21/Consts.h"

ThirdGameBotton::ThirdGameBotton()
{
    this->height = 97;
    this->width = 258;
    this->posX = 100;
    this->posY = 360;
    this->texture.loadFromFile("img/4Ace.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool ThirdGameBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
