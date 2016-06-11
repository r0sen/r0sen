#ifndef PILE_H
#define PILE_H
#include "card.h"
class Pile{
	private:
		Card card[30];
		int size;

	public:
	    Pile();
		void putCards();
		Card getCard();


};
#endif

