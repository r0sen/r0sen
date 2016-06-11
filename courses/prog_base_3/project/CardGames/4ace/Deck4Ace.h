#ifndef DECK4ACE_H
#define DECK4ACE_H
#include "card.h"
class Deck4Ace{
	private:
		Card card[48];
		int pos;

	public:
	    Deck4Ace();
		void putRandom();
		Card getCard();

};
#endif
