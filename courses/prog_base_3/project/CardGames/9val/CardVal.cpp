#include "CardVal.h"

CardVal::CardVal()
{
    this->posX = 200;
    this->posY = 200;
    this->width = 50;
    this->height = 50;
    this->visible = false;
}
bool CardVal::isClicked(int x, int y)
{
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y))
        return true;

    return false;
}
short int CardVal::getValueIdentifier()
{
	return valueIdentifier;
}

void CardVal::setValueIdentifier(short int valueInput)
{
	valueIdentifier = valueInput;
}

short int CardVal::getColorIdentifier()
{
	return colorIdentifier;
}

void CardVal::setColorIdentifier(short int id)
{
	colorIdentifier = id;
}

void CardVal::setTexture()
{
    this->texture.loadFromFile("img/finish_cards_sheet.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)1027/13 * (this->valueIdentifier), (float)615/5 * (this->colorIdentifier), (float)1027/13, (float)615/5 ));
    if(this->valueIdentifier == 4)
        this->sprite.setTextureRect(sf::IntRect(0, (float)615/5 * (this->colorIdentifier), (float)1027/13, (float)615/5 ));

}

