#ifndef DECK100_H
#define DECK100_H
#include "card.h"
class Deck100{
	private:
		Card card[48];
		int pos;

	public:
	    Deck100();
		void putRandom();
		Card getCard();

};
#endif
