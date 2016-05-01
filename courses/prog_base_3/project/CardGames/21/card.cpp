//#include "stdafx.h"

#include "card.h"
#include <string>
Card::Card(){

}

short int Card::getValueIdentifier()
{
	return valueIdentifier;
}
std::string Card::getImagePath()
{
	return imagePath;
}
void Card::setValueIdentifier(short int valueInput)
{
	valueIdentifier = valueInput;
}
void Card::setImagePath(std::string pathInput)
{
	imagePath = pathInput;
}

short int Card::getColorIdentifier()
{
	return colorIdentifier;
}

void Card::setColorIdentifier(short int id)
{
	colorIdentifier = id;
}

bool Card::isClicked(int x, int y)
{
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + height > y) && (this->posY < y))
        return true;

    return false;
}
