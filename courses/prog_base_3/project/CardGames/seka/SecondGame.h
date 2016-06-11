#include "Card.h"
#include "DeckSeka.h"
#include "RevealBottonSeka.h"
#include "PassBottonSeka.h"
#include "RestartBottonSeka.h"

#include "NextRoundBottonSeka.h"
#include "NextBottonSeka.h"
#include "RaiseBottonSeka.h"
#include "RepeatBottonSeka.h"

#include "Consts.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>


class SecondGame
{
public:
    SecondGame(RenderWindow* winInput);
    void start();
private:
    RenderWindow* win;


    RevealBottonSeka    *revealBottonSeka;
    RepeatBottonSeka    *repeatBottonSeka;
    NextRoundBottonSeka *nextRoundBottonSeka;
    NextBottonSeka      *nextBottonSeka;
    RaiseBottonSeka     *raiseBottonSeka;
    RestartBottonSeka   *restartBottonSeka;
    PassBottonSeka      *passBottonSeka;


    Card* opponent[3];
    Card* me[3];
    sf::Text bankThisGameText;
    sf::Text bankMeText;
    sf::Text bankOpponentText;
    sf::Text betOpponentText;
    sf::Text betMeText;
    sf::Text aiPass;
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
    DeckSeka* deck;
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

    void countSekaMe(Card *card);
    void countSekaOpponent(Card *card);

    void aiPassDo();
bool inHelp;
Text helpText;


};
