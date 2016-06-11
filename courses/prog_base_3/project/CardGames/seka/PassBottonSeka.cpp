#include "PassBottonSeka.h"
#include "Consts.h"

PassBottonSeka::PassBottonSeka()
{
    this->height = 79;
    this->width = 120;
    this->posX = 450;
    this->posY = SCREEN_HEIGHT - this->height;
    this->texture.loadFromFile("img/pass.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool PassBottonSeka::isPressed(float x, float y)
{
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
