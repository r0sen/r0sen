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
class Game
{
public:
    Game(RenderWindow* winInput);
    void start();
private:

    Deck *deck;
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

    int pointsTotal;

bool lastMe;
bool lastOpponent;

bool winMe;
bool winOpponent;



pair<int,int> cardChoice(int x, int y);
void pushSelectPair(pair<int,int> selectPair);
void testForWin();
void aiTurn();
void aiPushSelectPair(pair<int,int> selectPair);




};
