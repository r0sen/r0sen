#include "EndBotton.h"
#include "Consts.h"

EndBotton::EndBotton()
{
    this->height = 89;
    this->width = 135;
    this->posX = 150;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/end.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool EndBotton::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
