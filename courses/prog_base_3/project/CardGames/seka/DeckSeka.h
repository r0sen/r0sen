#ifndef DECKSEKA_H
#define DECKSEKA_H
#include "card.h"
class DeckSeka{
	private:
		Card card[64];
		int pos;

	public:
	    DeckSeka();
		void putRandom();
		Card getCard();

};
#endif
