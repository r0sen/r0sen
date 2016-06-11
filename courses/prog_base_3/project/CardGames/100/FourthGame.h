#include "Card.h"
#include "Deck100.h"
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
class FourthGame
{
public:
    FourthGame(RenderWindow* winInput);
    void start();
private:

    Deck100 *deck;
    /*
    list<Card> deck0;
    list<Card> deck1;
    list<Card> deck2;
    list<Card> deck3;
    list<Card> deck4;*/
    RenderWindow* win;

    list<pair<int,int> > me;
    list<pair<int,int> > opponent;
    list<pair<int,int> > deck0;
    Sprite spritesMe[24];
    Texture texturesMe[24];
    Texture deck0Texture;

    Sprite spritesOpponent[24];
    Texture texturesOpponent[24];
    Sprite deck0Sprite;

sf::Text pointsTotalText;
void refreshText();
    int pointsTotal;

bool lastMe;
bool lastOpponent;

bool winMe;
bool winOpponent;
bool inHelp;

Text helpText;

pair<int,int> cardChoice(int x, int y);
void pushSelectPair(pair<int,int> selectPair);
void testForWin();
void aiTurn();
void aiPushSelectPair(pair<int,int> selectPair);
int sizeCallBack;
    CallbackFunction cb[3];
void win_subscribe(CallbackFunction callback);
void this_is_callback_fn(bool lastMy, bool lastOpp, int pointsGame);
bool gameEnded;
bool mePush;
bool drawDeck0;
void restart();
};
