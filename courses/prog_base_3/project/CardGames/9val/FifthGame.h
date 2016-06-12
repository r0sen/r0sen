#include "CardVal.h"
#include "DeckFifth.h"
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
class FifthGame
{
public:
    FifthGame(RenderWindow* winInput);
    void start();
private:

DeckFifth *deck;
DeckFifth *deck2;
CardVal myCard;
    RenderWindow* win;

    int bankTotal;
sf::Text bankTotalText;

    int bit;
sf::Text bitText;

CardVal table[9];
void refreshText();

void restart();

bool roundEnded;
void reveal();
void winLook();
void bitSet();
void nextRound2();
bool gameWin;
bool gameLose;
bool    inHelp;
Text helpText;

};
