#include "Card.h"
#include "Deck.h"
#include "NextBotton.h"
#include "EndBotton.h"
#include "RestartBotton.h"
//#include "RaiseBtn.h"
#include "Consts.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>


class Game
{
public:
    Game(RenderWindow* winInput);
    void start();
private:
    RenderWindow* win;
    void nextRound();
    Card* opponent[5];
    Card* me[5];
    Deck* deck;
    int rateMe;
    int rateOpponent;
    int countSteps;
    NextBotton* nextButton;
    EndBotton* endButton;
    RestartBotton* restartButton;
    void testForWinFinal();
    bool finishedGame;
    bool winMe;
    bool winOpponent;
    bool both;
    void testForWinSkip();
    void nextDistribution();

};
