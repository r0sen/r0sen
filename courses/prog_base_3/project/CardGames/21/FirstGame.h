#include "Card.h"
#include "Deck.h"
#include "NextBotton.h"
#include "EndBotton.h"
#include "RestartBotton.h"
#include "Consts.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>


class FirstGame
{
public:
    FirstGame(RenderWindow* winInput);
    void start();
private:
    RenderWindow* win;
    void nextRound();
    Card* opponent[7];
    Card* me[7];
    Deck* deck;
    int rateMe;
    int rateOpponent;
    int countSteps;
    int countStepsMe;
    int countStepsOpponent;
    NextBotton* nextButton;
    EndBotton* endButton;
    RestartBotton* restartButton;
    void testForWinFinal();
    bool finishedFirstGame;
    bool winMe;
    bool winOpponent;
    bool both;
    void testForWinSkip();
    void restartFirstGame();
    bool aiTurn();
    void rateMeFn();
    void rateOpponentFn();
bool inHelp;
Text helpText;

};
