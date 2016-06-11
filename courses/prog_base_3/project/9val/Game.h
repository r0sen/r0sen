#include "Card.h"
#include "Deck.h"
#include <map>   
#include <string.h>




#include "Consts.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
//#include <deque>
#include <list>

using namespace std;
typedef void (*CallbackFunction)(bool , bool, int);
class Game
{
public:
    Game(RenderWindow* winInput);
    void start();
private:

    Deck *deck;
Deck *deck2;
Card myCard;
    RenderWindow* win;

    int bankTotal;
sf::Text bankTotalText;

    int bit;
sf::Text bitText;

Card table[9];
void refreshText();

void restart();

bool roundEnded;
void reveal();
void winLook();
void bitSet();
void nextRound2();
bool gameWin;
bool gameLose;
};
