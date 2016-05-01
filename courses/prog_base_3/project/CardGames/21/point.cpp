#include "deck.h"

class Me
{
    public:
    Card cards [10];
    int counter=0;
};
class Opponent
{
        public:

    Card cards [10];
    int counter=0;
};
class Point{
public:
Deck deck;
Opponent opponent;
Me me;
void setCard();
void testForWinSkip();
void testForWinFinal();
};
void Point::setCard()
{

    this->me.cards[this->me.counter++] = this->deck.getCard();
    this->opponent.cards[this->opponent.counter++] = this->deck.getCard();


}
void Point::testForWinSkip()
{
    int rateMe=0;
    int rateOpponent=0;
    for(int i = 0; i<= this->me.counter; i++)
    {
        rateMe+=this->me.cards[i].getValueIdentifier();
        if(rateMe==21)
            printf("U WIN!!!!");
        if(rateMe>21)
            printf("U LOOSE!!!!");
    }

        for(int i = 0; i<= this->opponent.counter; i++)
    {
        rateOpponent+=this->opponent.cards[i].getValueIdentifier();
        if(rateOpponent==21)
        printf("U LOOSE!!!!");
        if(rateOpponent>21)
        printf("U WIN!!!!");
    }

}
void Point::testForWinFinal()
{
    int rateMe=0;
    int rateOpponent=0;
    for(int i = 0; i<= this->me.counter; i++)
    {
        rateMe+=this->me.cards[i].getValueIdentifier();
    }

        for(int i = 0; i<= this->opponent.counter; i++)
    {
        rateOpponent+=this->opponent.cards[i].getValueIdentifier();
    }
    if(rateOpponent>rateMe)
    printf("U LOOSE!!!!");
    else
        printf("U WIN!!!!");
}
