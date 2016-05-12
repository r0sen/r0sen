#include "NextRoundBotton.h"
#include "Consts.h"

NextRoundBotton::NextRoundBotton()
{
    this->height = 79;
    this->width = 120;
    this->posX = 600;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/next_round.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool NextRoundBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
