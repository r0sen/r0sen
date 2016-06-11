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


    Sprite deckSprite0;
    Sprite deckSprite1;
    Sprite deckSprite2;
    Sprite deckSprite3;
    Sprite deckSprite4;

    Texture cardTexture0;
    Texture cardTexture1;
    Texture cardTexture2;
    Texture cardTexture3;
    Texture cardTexture4;
    list<pair<int,int> > deck0;
    pair<int,int> deck1[14];
    pair<int,int> deck2[14];
    pair<int,int> deck3[14];
    pair<int,int> deck4[14];

    int size1;
    int size2;
    int size3;
    int size4;





void deck1Accept();
void deck2Accept();
void deck3Accept();
void deck4Accept();

void missedClick();

void restartGame();


};
