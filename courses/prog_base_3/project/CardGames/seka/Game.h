#include "Card.h"
#include "Deck.h"
#include "RevealBotton.h"
#include "PassBotton.h"
#include "RestartBotton.h"

#include "NextRoundBotton.h"
#include "NextBotton.h"
#include "RaiseBotton.h"
#include "RepeatBotton.h"

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


    RevealBotton    *revealBotton;
    RepeatBotton    *repeatBotton;
    NextRoundBotton *nextRoundBotton;
    NextBotton      *nextBotton;
    RaiseBotton     *raiseBotton;
    RestartBotton   *restartBotton;
    PassBotton      *passBotton;


    Card* opponent[3];
    Card* me[3];
    sf::Text bankThisGameText;
    sf::Text bankMeText;
    sf::Text bankOpponentText;
    sf::Text betOpponentText;
    sf::Text betMeText;
    sf::Text betText[5];
    int *bank;
    int bankThisGame;
    int bankMe;
    int bankOpponent;
    int betMe;
    int betOpponent;
    int pointsMe;
    int pointsOpponent;
    int bet[5];
    bool inRound;
    bool endGame;
    bool winMe;
    bool winOpponent;
    Deck* deck;
    void refreshText();
    void nextBetMe();
    void raiseBetMe();

    void repeatBetOpponent();
    void raiseBetOpponent();
    void countPointsMe();
    void countPointsOpponent();

    void aiTurn();
    void nextDo();
    void raiseDo();
    void nextBetMeDo();
    void lookForWinner();
    void showCardsOpponent();
    void revealDo();
    void passDo();
    void restartGame();
    void fillCards();
    void restartDo();
    void nextRound();
    void nextRoundDo();


};
