#ifndef DECKFIFTH_H
#define DECKFIFTH_H
#include "card.h"
class DeckFifth{
	private:
		Card card[48];
		int pos;

	public:
	    DeckFifth();
		void putRandom();
		Card getCard();

};
#endif
