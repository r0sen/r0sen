#include "RepeatBotton.h"
#include "Consts.h"

RepeatBotton::RepeatBotton()
{
    this->height = 79;
    this->width = 120;
    this->posX = 0;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/repeat.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool RepeatBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
