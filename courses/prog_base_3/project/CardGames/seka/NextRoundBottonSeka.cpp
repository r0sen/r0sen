#include "NextRoundBottonSeka.h"
#include "Consts.h"

NextRoundBottonSeka::NextRoundBottonSeka()
{
    this->height = 79;
    this->width = 120;
    this->posX = 600;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/next_round.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool NextRoundBottonSeka::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
