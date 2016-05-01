#include "deck.h"
#include <stdlib.h>

Deck::Deck()
{
	pos = 0;
	int colorID = 0;
	int valueID = 0;
	int counter = 0;
	for (int  i = 0; valueID<13; i++)
	{
		//card[i] = new Card();
		card[i].setColorIdentifier(colorID);
		card[i].setValueIdentifier(valueID);


       counter++;
		if (counter > 3)
		{
			counter = 0;
			valueID++;
		}

	}
}

void Deck::putRandom()
{
    srand(0);
	Card cardSwipe; //= new Card();
	int id1, id2;
	for (int i = 0; i < 1000; i++)
	{
		id1 = rand() % 52;
		id2 = rand() % 52;
		cardSwipe = card[id1];
		card[id1] = card[id2];
		card[id2] = cardSwipe;
	}
}

Card Deck::getCard()
{
	pos++;
	return card[pos-1];
}
