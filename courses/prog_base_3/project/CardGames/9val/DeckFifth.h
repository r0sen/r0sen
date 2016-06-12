#ifndef DECKFIFTH_H
#define DECKFIFTH_H
#include "CardVal.h"
class DeckFifth{
	private:
		CardVal card[48];
		int pos;

	public:
	    DeckFifth();
		void putRandom();
		CardVal getCard();

};
#endif
