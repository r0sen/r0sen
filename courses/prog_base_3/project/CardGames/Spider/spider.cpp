#include <stack>
#include "card.h"
#include "deck.h"



void spider()
{
    std::stack <Card> stack1;
    std::stack <Card> stack2;
    std::stack <Card> stack3;
    std::stack <Card> stack4;
    std::stack <Card> stack5;
    std::stack <Card> stack6;
    std::stack <Card> stack7;
    std::stack <Card> stack8;
    std::stack <Card> stack9;
    std::stack <Card> stack10;
    std::stack <Card> stack11;
    Deck deck1, deck2;

    for(int i = 0; i<4;i++)
    {
      //  pushCard(*stack1,*deck1);
    }
}
static void pushCard(std::stack <Card> * stackN, Deck *deck)
{
stackN->push(deck->getCard());
}


static void putInStartPosition()
{

}
