#include "DeckSeka.h"
DeckSeka::DeckSeka()
{
	this->pos = 0;
	int colorID = 0;
	int valueID = 4;
	for (int  i = 0; i < 36; i++)
	{
		this->card[i].setColorIdentifier(colorID);
		this->card[i].setValueIdentifier(valueID);

		colorID++;

		if (colorID > 3)
		{
			colorID = 0;
			valueID++;
		}
	}
}

void DeckSeka::putRandom()
{
    srand(std::time(0));
	Card cardSwipe;
	int id1, id2;
	for (int i = 0; i < 100; i++)
	{
		id1 = rand() % 36;
		id2 = rand() % 36;
		cardSwipe = this->card[id1];
		this->card[id1] = this->card[id2];
		this->card[id2] = cardSwipe;
	}
}

Card DeckSeka::getCard()
{

	if (pos>10)
        pos = 0;
    pos++;
	return card[pos-1];
}
