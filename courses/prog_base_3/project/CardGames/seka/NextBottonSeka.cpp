#include "NextBottonSeka.h"
#include "Consts.h"

NextBottonSeka::NextBottonSeka()
{
    this->height = 79;
    this->width = 120;
    this->posX = 0;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/next.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool NextBottonSeka::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
