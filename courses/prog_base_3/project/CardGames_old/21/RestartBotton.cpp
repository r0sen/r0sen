#include "RestartBotton.h"
#include "Consts.h"

RestartBotton::RestartBotton()
{
    this->height = 89;
    this->width = 135;
    this->posX = SCREEN_WIDTH - this->width;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/restart.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool RestartBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

