#include "Game.h"
#include <sstream>
#include <iostream>


bool counter;
Game::Game(RenderWindow* winInput)
{
    this->win = winInput;
    //int bank;
    this->deck = new Deck();
    for (int i = 0; i < 3; i++)
    {
        this->opponent[i] = new Card();
        this->me[i] = new Card();
    }
    this->bankThisGame = 0;
  this->bankMe = 100;
    this->bankOpponent = 100;
    this->betMe = 5;
   this-> betOpponent = 5;
    this->pointsMe = 0;
   this-> pointsOpponent = 0;

}

void Game::repeatBetMe()
{
    this->bankThisGame = this->bankThisGame + this->betOpponent;
    this->betMe +=5;
    this->bankMe=this->bankMe - this->betOpponent;
    this->nextDo();
    }

void Game::raiseBetMe()
{
    this->bankThisGame = this->bankThisGame + this->betOpponent + 5;
    this->bankMe=this->bankMe - this->betOpponent - 5;
    this->betMe+=5;
}

void Game::repeatBetOpponent()
{
    this->bankThisGame = this->bankThisGame + this->betMe;
        this->betOpponent +=5;

    this->bankOpponent=this->bankOpponent - this->betMe;
}

void Game::raiseBetOpponent()
{
    this->bankThisGame = this->bankThisGame + this->betMe + 5;
    this->bankOpponent=this->bankOpponent - this->betMe - 5;
    this->betOpponent+=5;
}

void Game::countPointsMe()
{
    if((this->me[0]->getColorIdentifier() == this->me[1]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() == this->me[2]->getColorIdentifier()))
    {
        for (int i = 0; i<3; i++)
        {
            this->pointsMe+=this->me[i]->getValueIdentifier();
        }
    }

    if ((this->me[0]->getColorIdentifier() == this->me[1]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() != this->me[2]->getColorIdentifier()))
        this->pointsMe=this->me[0]->getValueIdentifier() + this->me[1]->getValueIdentifier();

    if ((this->me[0]->getColorIdentifier() == this->me[2]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() != this->me[1]->getColorIdentifier()))
        this->pointsMe=this->me[0]->getValueIdentifier() + this->me[2]->getValueIdentifier();

    if ((this->me[1]->getColorIdentifier() == this->me[2]->getColorIdentifier()) && (this->me[1]->getColorIdentifier() != this->me[0]->getColorIdentifier()))
        this->pointsMe=this->me[1]->getValueIdentifier() + this->me[2]->getValueIdentifier();

    if((this->me[0]->getColorIdentifier() != this->me[1]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() != this->me[2]->getColorIdentifier()) && (this->me[1]->getColorIdentifier() != this->me[2]->getColorIdentifier()))
    {
        pointsMe = this->me[0]->getValueIdentifier();
        for (int i = 1; i < 3; i++)
        {
            if (this->me[i]->getValueIdentifier() > pointsMe)
                pointsMe = this->me[i]->getValueIdentifier();
        }
    }

    if ((this->me[0]->getValueIdentifier() == this->me[1]->getValueIdentifier()) && (this->me[0]->getValueIdentifier() == this->me[2]->getValueIdentifier()))
    {
        if (this->me[0]->getValueIdentifier() == 6)
            this->pointsMe = 666;
        if (this->me[0]->getValueIdentifier() == 0)
            this->pointsMe = 111;
    }

}

void Game::countPointsOpponent()
{
    if((this->opponent[0]->getColorIdentifier() == this->opponent[1]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() == this->opponent[2]->getColorIdentifier()))
    {
        for (int i = 0; i<3; i++)
        {
            this->pointsOpponent+=this->opponent[i]->getValueIdentifier();
        }
    }

    if ((this->opponent[0]->getColorIdentifier() == this->opponent[1]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() != this->opponent[2]->getColorIdentifier()))
        this->pointsOpponent=this->opponent[0]->getValueIdentifier() + this->opponent[1]->getValueIdentifier();

    if ((this->opponent[0]->getColorIdentifier() == this->opponent[2]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() != this->opponent[1]->getColorIdentifier()))
        this->pointsOpponent=this->opponent[0]->getValueIdentifier() + this->opponent[2]->getValueIdentifier();

    if ((this->opponent[1]->getColorIdentifier() == this->opponent[2]->getColorIdentifier()) && (this->opponent[1]->getColorIdentifier() != this->opponent[0]->getColorIdentifier()))
        this->pointsOpponent=this->opponent[1]->getValueIdentifier() + this->opponent[2]->getValueIdentifier();

    if((this->opponent[0]->getColorIdentifier() != this->opponent[1]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() != this->opponent[2]->getColorIdentifier()) && (this->opponent[1]->getColorIdentifier() != this->opponent[2]->getColorIdentifier()))
    {
        pointsOpponent = this->opponent[0]->getValueIdentifier();
        for (int i = 1; i < 3; i++)
        {
            if (this->opponent[i]->getValueIdentifier() > pointsOpponent)
                pointsOpponent = this->opponent[i]->getValueIdentifier();
        }
    }

    if ((this->opponent[0]->getValueIdentifier() == this->opponent[1]->getValueIdentifier()) && (this->opponent[0]->getValueIdentifier() == this->opponent[2]->getValueIdentifier()))
    {
        if (this->opponent[0]->getValueIdentifier() == 6)
            this->pointsOpponent = 666;
        if (this->opponent[0]->getValueIdentifier() == 0)
            this->pointsOpponent = 111;
    }

}

void Game::aiTurn()
{
    this->countPointsOpponent();
    if(this->pointsOpponent > 15)
        this->raiseBetOpponent();
    else
        this->repeatBetOpponent();


}


void Game::repeatDo()
{
    this->repeatBetMe();
}


void Game::raiseDo()
{
    this->raiseBetMe();
}


void Game::nextDo()
{
    this->aiTurn();
}
void Game::lookForWinner()
{
    if(this->pointsMe >= this->pointsOpponent)
        this->bankMe+=this->bankThisGame;
    else
        this->bankOpponent+=this->bankThisGame;

    this->bankThisGame = 0 ;
}



void Game::showCardsOpponent()
{
    for (int i = 0; i < 3; i++)
    {
        this->opponent[i]->setTexture();
        this->opponent[i]->visible = true;
    }
}
void Game::revealDo()
{
    this->countPointsMe();
    this->countPointsOpponent();
    this->lookForWinner();
    this->showCardsOpponent();
}
void Game::passDo()
{
    this-> bankOpponent += this->bankThisGame;
    this->bankThisGame = 0;
    this->showCardsOpponent();
}

void Game::restartGame()
{
    bankThisGame = 0;
    bankMe = 100;
    bankOpponent = 100;
    betMe = 5;
    betOpponent = 5;
    pointsMe = 0;
    pointsOpponent = 0;
    this->fillCards();

}

void Game::fillCards()
{
    this->deck->putRandom();
    for (int i = 0; i < 3; i++)
    {
        //this->opponent[i] = new Card();
        *opponent[i] = deck->getCard();
        opponent[i]->sprite.setPosition(i * 100 + 190, 100);
        opponent[i]->texture.loadFromFile("img/finish_cards_sheet.png");
        opponent[i]->sprite.setTextureRect(sf::IntRect(0, (float) 492/1, (float)1027/13, (float)615/5 ));
        opponent[i]->sprite.setTexture(opponent[i]->texture);

        //this->me[i] = new Card();
        *me[i] = deck->getCard();
        me[i]->sprite.setPosition(i * 100 + 190, 300);
        me[i]->setTexture();
        me[i]->visible = true;
    }
}



void Game::restartDo()
{
    this->restartGame();

}


void Game::start()
{

    //bank = 0;
    for (int i = 0; i < 5; i++)
        bet[i] = 0;
//    round = 0;

    this->deck->putRandom();
    Texture cardTexture;
    Sprite background;
    Texture backTexture;
    backTexture.loadFromFile("img/wood-texture.jpg");
    background.setTexture(backTexture);
    background.setPosition(0, 0);
    //background.setScale((float)SCREEN_WIDTH/400, (float)SCREEN_HEIGHT/ 300);


//U WIN U LOSE PICS

    Sprite lose;
    Texture uLose;
    uLose.loadFromFile("img/lose.png");
    lose.setTexture(uLose);
    lose.setPosition(300, 444);

    Sprite winn;
    Texture uWin;
    uWin.loadFromFile("img/win.png");
    winn.setTexture(uWin);
    winn.setPosition(300, 444);


    Sprite both;
    Texture theBoth;
    theBoth.loadFromFile("img/both.png");
    both.setTexture(theBoth);
    both.setPosition(300, 444);

    // BUTTONS
//this->nextButton = new NextBotton();
//    this->endButton = new EndBotton();
    //restartBotton = new RestartBotton();

    this->revealBotton = new RevealBotton();
    this->repeatBotton = new RepeatBotton();
    this->nextRoundBotton = new NextRoundBotton();
    //this->raiseBotton = new RaiseBotton();
    this->restartBotton = new RestartBotton();
    this->passBotton = new PassBotton();

    for (int i = 0; i < 3; i++)
    {
        this->opponent[i] = new Card();
        *opponent[i] = deck->getCard();
        opponent[i]->sprite.setPosition(i * 100 + 190, 100);
        opponent[i]->setTexture();
        opponent[i]->visible = true;

        this->me[i] = new Card();
        *me[i] = deck->getCard();
        me[i]->sprite.setPosition(i * 100 + 190, 300);
        me[i]->setTexture();
        me[i]->visible = true;
    }
// put cards in start POSITION
    for (int i = 0; i<3; i++)
    {
        opponent[i]->texture.loadFromFile("img/finish_cards_sheet.png");
        opponent[i]->sprite.setTextureRect(sf::IntRect(0, (float) 492/1, (float)1027/13, (float)615/5 ));
        opponent[i]->sprite.setTexture(opponent[0]->texture);
    }



    bankOpponentText.setCharacterSize(24);
    bankMeText.setCharacterSize(24);
    bankThisGameText.setCharacterSize(24);
    betMeText.setCharacterSize(24);
    betOpponentText.setCharacterSize(24);




    bankOpponentText.setPosition(20, 20);
    //betText[0].setPosition(SCREEN_WIDTH/2 - 20, SCREEN_HEIGHT - 170);
    betOpponentText.setPosition(100, 150);
    betMeText.setPosition(100, 290);
    //betText[3].setPosition(SCREEN_WIDTH - 100, 150);
   // betText[4].setPosition(SCREEN_WIDTH - 100, 290);
    bankMeText.setPosition(5, 400);
    bankThisGameText.setPosition(20, SCREEN_HEIGHT/2 - 50);


    sf::Font font;
    font.loadFromFile("fonts/times.ttf");
    bankMeText.setFont(font);
    bankOpponentText.setFont(font);
    betMeText.setFont(font);
    betOpponentText.setFont(font);
    bankThisGameText.setFont(font);

    for(int i = 0; i < 5; i++)
    {
        betText[i].setFont(font);
    }

    /**
       sf::Text test;
       test.setCharacterSize(25);
       test.setPosition( 20, 20);
        sf::Font testFont;
        testFont.loadFromFile("fonts/times.ttf");
        test.setFont(testFont);
       test.setString("TEST!!!!!!!!!");
    **/




    while (this->win->isOpen())
    {
        Event event;
        while (this->win->pollEvent(event))
        {
            if (event.type == Event::Closed)
                this->win->close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (repeatBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                            repeatDo();

                    if (passBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                            passDo();

                    if (restartBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                            restartDo();

                    if (revealBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                            revealDo();

                    //if (raiseBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        //    raiseDo();

                    if (nextRoundBotton->isPressed(event.mouseButton.x, event.mouseButton.y));
                        // next
                    //this->win->close(); // @TODO: finish game
                }
            }
        }

        this->refreshText();
        this->win->clear();
        this->win->draw(background);

        for (int i = 0; i <3; i++)
        {

                this->win->draw(me[i]->sprite);


                this->win->draw(opponent[i]->sprite);
        }



        this->win->draw(bankMeText);
        this->win->draw(bankOpponentText);
        this->win->draw(bankThisGameText);
        this->win->draw(betMeText);
        this->win->draw(betOpponentText);

        //this->win->draw(test);
        for (int i = 0; i < 5; i++)
            win->draw(betText[i]);
        this->win->draw(restartBotton->sprite);
        this->win->draw(nextRoundBotton->sprite);
        this->win->draw(revealBotton->sprite);
        this->win->draw(passBotton->sprite);
        //this->win->draw(raiseBotton->sprite);
        this->win->draw(repeatBotton->sprite);
        this->win->display();
    }
}
void Game::refreshText()
{
    std::stringstream ss;
    ss.clear();
    ss << bankMe;
    bankMeText.setString("You Bank: " + ss.str());

    ss.str("");
    ss << bankOpponent;
    bankOpponentText.setString("AI Bank: " + ss.str());

    ss.str("");

    ss.clear();
    ss << bankThisGame;
    bankThisGameText.setString("" + ss.str());
    ss.str("");

    ss.clear();
    ss << betMe;
    betMeText.setString(  ""+ ss.str());

    ss.str("");

    ss.clear();
    ss << betOpponent;
    betOpponentText.setString(  ss.str());





}
