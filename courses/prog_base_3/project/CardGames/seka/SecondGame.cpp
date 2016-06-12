#include "SecondGame.h"
#include <sstream>
#include <iostream>
#include <SFML/Audio.hpp>


bool counter;
SecondGame::SecondGame(RenderWindow* winInput)
{
    this->win = winInput;
    //int bank;
    this->deck = new DeckSeka();
    for (int i = 0; i < 3; i++)
    {
        this->opponent[i] = new Card();
        this->me[i] = new Card();
    }
    this->bankThisGame = 10;
    this->bankMe = 95;
    this->bankOpponent = 95;
    this->betMe = 5;
    this-> betOpponent = 5;
    this->pointsMe = 0;
    this-> pointsOpponent = 0;
    this->inRound = true;
    this->endGame = false;
    this->winMe = false;
    this->winOpponent = false;
        this->inHelp = false;

}

void SecondGame::nextBetMe()
{
    if(this->bankMe-this->betOpponent <= 0 )
    {
        this->bankThisGame += this->bankMe;
        this->bankMe = 0;
        revealDo();
    }


    this->nextDo();
    if (this->betOpponent == this->betMe)
    {
        this->bankThisGame = this->bankThisGame + this->betOpponent;
        this->betMe =betMe;
        this->bankMe-= this->betMe;
    }
    else
    {
        this->betMe =this->betOpponent;
        this->bankMe-= this->betMe;
    }

}

void SecondGame::raiseBetMe()
{
    if(this->bankMe-this->betOpponent <=0 )
    {
        this->bankThisGame += this->bankMe;
        this->bankMe = 0;
        revealDo();
    }

    //this->bankThisGame = this->bankThisGame  + 5;
    //this->bankMe=this->bankMe  - 5;
    this->betMe+=5;
}

void SecondGame::repeatBetOpponent()
{
    if(this->bankOpponent-this->betMe <=0 )
    {
        this->bankThisGame += this->bankOpponent;
        this->bankOpponent = 0;
        revealDo();
    }

    this->bankThisGame += this->betMe;
    this->betOpponent =this->betMe;

    this->bankOpponent=this->bankOpponent - this->betMe;
}

void SecondGame::raiseBetOpponent()
{
    if(this->bankOpponent-this->betMe <= 0 )
    {
        this->bankThisGame += this->bankOpponent;
        this->bankOpponent = 0;
        revealDo();
    }
    this->bankThisGame = this->bankThisGame + this->betMe + 5;
    this->bankOpponent=this->bankOpponent - this->betMe - 5;
    this->betOpponent+=5;
}

void SecondGame::countPointsMe()
{
    int gameValue = 0;
    if((this->me[0]->getColorIdentifier() == this->me[1]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() == this->me[2]->getColorIdentifier()))
    {
        for (int i = 0; i<3; i++)
        {
            this->pointsMe+=this->me[i]->getValueIdentifier();
          this->countSekaMe(this->me[i]);

        }
    }

    if ((this->me[0]->getColorIdentifier() == this->me[1]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() != this->me[2]->getColorIdentifier()))
        {


        this->pointsMe=this->me[0]->getValueIdentifier() + this->me[1]->getValueIdentifier();
                  this->countSekaMe(this->me[0]);
          this->countSekaMe(this->me[1]);


        }
    if ((this->me[0]->getColorIdentifier() == this->me[2]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() != this->me[1]->getColorIdentifier()))
        {
            this->pointsMe=this->me[0]->getValueIdentifier() + this->me[2]->getValueIdentifier();
                            this->countSekaMe(this->me[0]);
          this->countSekaMe(this->me[2]);
        }
    if ((this->me[1]->getColorIdentifier() == this->me[2]->getColorIdentifier()) && (this->me[1]->getColorIdentifier() != this->me[0]->getColorIdentifier()))
       {
           this->pointsMe=this->me[1]->getValueIdentifier() + this->me[2]->getValueIdentifier();
                           this->countSekaMe(this->me[2]);
          this->countSekaMe(this->me[1]);
       }
    if((this->me[0]->getColorIdentifier() != this->me[1]->getColorIdentifier()) && (this->me[0]->getColorIdentifier() != this->me[2]->getColorIdentifier()) && (this->me[1]->getColorIdentifier() != this->me[2]->getColorIdentifier()))
    {
        pointsMe = this->me[0]->getValueIdentifier();
        int setter = 0;
        for (int i = 1; i < 3; i++)
        {
            if (this->me[i]->getValueIdentifier() > pointsMe)
                {pointsMe = this->me[i]->getValueIdentifier();
                setter++;}
        }
                        this->countSekaMe(this->me[setter]);

    }

    if ((this->me[0]->getValueIdentifier() == this->me[1]->getValueIdentifier()) && (this->me[0]->getValueIdentifier() == this->me[2]->getValueIdentifier()))
    {
        if (this->me[0]->getValueIdentifier() == 6)
            this->pointsMe = 666;
        if (this->me[0]->getValueIdentifier() == 0)
            this->pointsMe = 111;
    }
printf("\nPointsMe = %i", this->pointsMe);
}

void SecondGame::countSekaOpponent(Card *card)
{
        if(card->getValueIdentifier()== 10)
            this->pointsOpponent -=1;
        if(card->getValueIdentifier()== 11)
            this->pointsOpponent -=2;
        if(card->getValueIdentifier()== 13)
            this->pointsOpponent -=3;
        if(card->getValueIdentifier()== 4)
            this->pointsOpponent +=7;
}

void SecondGame::countSekaMe(Card *card)
{
        if(card->getValueIdentifier()== 10)
            this->pointsMe -=1;
        if(card->getValueIdentifier()== 11)
            this->pointsMe -=2;
        if(card->getValueIdentifier()== 13)
            this->pointsMe -=3;
        if(card->getValueIdentifier()== 4)
            this->pointsMe +=7;
}
void SecondGame::countPointsOpponent()
{
    int gameValue = 0;
    if((this->opponent[0]->getColorIdentifier() == this->opponent[1]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() == this->opponent[2]->getColorIdentifier()))
    {
        for (int i = 0; i<3; i++)
        {
            this->pointsOpponent+=this->opponent[i]->getValueIdentifier();
          this->countSekaOpponent(this->opponent[i]);

        }
    }

    if ((this->opponent[0]->getColorIdentifier() == this->opponent[1]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() != this->opponent[2]->getColorIdentifier()))
        {


        this->pointsOpponent=this->opponent[0]->getValueIdentifier() + this->opponent[1]->getValueIdentifier();
                  this->countSekaOpponent(this->opponent[0]);
          this->countSekaOpponent(this->opponent[1]);


        }
    if ((this->opponent[0]->getColorIdentifier() == this->opponent[2]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() != this->opponent[1]->getColorIdentifier()))
        {
            this->pointsOpponent=this->opponent[0]->getValueIdentifier() + this->opponent[2]->getValueIdentifier();
                            this->countSekaOpponent(this->opponent[0]);
          this->countSekaOpponent(this->opponent[2]);
        }
    if ((this->opponent[1]->getColorIdentifier() == this->opponent[2]->getColorIdentifier()) && (this->opponent[1]->getColorIdentifier() != this->opponent[0]->getColorIdentifier()))
       {
           this->pointsOpponent=this->opponent[1]->getValueIdentifier() + this->opponent[2]->getValueIdentifier();
                           this->countSekaOpponent(this->opponent[2]);
          this->countSekaOpponent(this->opponent[1]);
       }
    if((this->opponent[0]->getColorIdentifier() != this->opponent[1]->getColorIdentifier()) && (this->opponent[0]->getColorIdentifier() != this->opponent[2]->getColorIdentifier()) && (this->opponent[1]->getColorIdentifier() != this->opponent[2]->getColorIdentifier()))
    {
        pointsOpponent = this->opponent[0]->getValueIdentifier();
        int setter = 0;
        for (int i = 1; i < 3; i++)
        {
            if (this->opponent[i]->getValueIdentifier() > pointsOpponent)
                {pointsOpponent = this->opponent[i]->getValueIdentifier();
                setter++;}
        }
                        this->countSekaOpponent(this->opponent[setter]);

    }

    if ((this->opponent[0]->getValueIdentifier() == this->opponent[1]->getValueIdentifier()) && (this->opponent[0]->getValueIdentifier() == this->opponent[2]->getValueIdentifier()))
    {
        if (this->opponent[0]->getValueIdentifier() == 6)
            this->pointsOpponent = 666;
        if (this->opponent[0]->getValueIdentifier() == 0)
            this->pointsOpponent = 111;
    }
printf("\nPointsOpponent = %i", this->pointsOpponent);
}

void SecondGame::aiTurn()
{
    srand(std::time(0));
    this->countPointsOpponent();
    if(this->pointsOpponent < 9 && (rand()%2 ==1))
        this->aiPassDo();
    if((this->pointsOpponent > 18)&&(rand()%3 ==1))
        this->raiseBetOpponent();

    else
        this->repeatBetOpponent();


}

void SecondGame::aiPassDo()
{
       this-> bankMe += this->bankThisGame;
    this->bankThisGame = 0;
    this->betMe = 0;
    this->betOpponent = 0;
    this->showCardsOpponent();
    this->inRound = false;
            this->win->draw(this->aiPass);

}
void SecondGame::nextBetMeDo()
{
    this->nextBetMe();
}


void SecondGame::raiseDo()
{
    this->raiseBetMe();
}


void SecondGame::nextDo()
{
    this->aiTurn();
}
void SecondGame::lookForWinner()
{
    if(this->pointsMe >= this->pointsOpponent)
        this->bankMe+=this->bankThisGame;
    else
        this->bankOpponent+=this->bankThisGame;

    this->bankThisGame = 0 ;
}



void SecondGame::showCardsOpponent()
{
    for (int i = 0; i < 3; i++)
    {
        this->opponent[i]->setTexture();
        this->opponent[i]->visible = true;
    }
}
void SecondGame::revealDo()
{
    this->countPointsMe();
    this->countPointsOpponent();
    this->lookForWinner();
    this->showCardsOpponent();
    this->bankThisGame = 0;
    this->betMe = 0;
    this->betOpponent = 0;

}
void SecondGame::passDo()
{
    this-> bankOpponent += this->bankThisGame;
    this->bankThisGame = 0;
    this->betMe = 0;
    this->betOpponent = 0;
    this->showCardsOpponent();
    this->inRound = false;
}

void SecondGame::restartGame()
{
    bankThisGame = 10;
    bankMe = 95;
    bankOpponent = 95;
    betMe = 5;
    betOpponent = 5;
    pointsMe = 0;
    pointsOpponent = 0;
    this->inRound = true;
    this->fillCards();
    this->endGame = false;

}

void SecondGame::nextRound()
{

    revealDo();
    bankThisGame = 10;
    bankMe -= 5;
    bankOpponent -= 5;
    betMe = 5;
    betOpponent = 5;
    pointsMe = 0;
    pointsOpponent = 0;
    this->fillCards();
    this->inRound = true;

}
void SecondGame::nextRoundDo()
{

    this->nextRound();
}
void SecondGame::fillCards()
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



void SecondGame::restartDo()
{
    this->restartGame();

}


void SecondGame::start()
{

    sf::Music music;
    if (!music.openFromFile("sounds/6.ogg"))
    {
        return; // error
    }
    music.play();
    music.setLoop(true);

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
    uLose.loadFromFile("img/uLose.jpg");
    lose.setTexture(uLose);
    lose.setPosition(600, 200);

    Sprite winn;
    Texture uWin;
    uWin.loadFromFile("img/uWin.jpg");
    winn.setTexture(uWin);
    winn.setPosition(600, 200);


    Sprite both;
    Texture theBoth;
    theBoth.loadFromFile("img/both.png");
    both.setTexture(theBoth);
    both.setPosition(600, 200);

    // BUTTONS
    this->nextBottonSeka = new NextBottonSeka();
//    this->endButton = new EndBottonSeka();
    //restartBottonSeka = new RestartBottonSeka();

    this->revealBottonSeka = new RevealBottonSeka();
    this->nextBottonSeka = new NextBottonSeka();
    //this->repeatBottonSeka = new RepeatBottonSeka();
    this->nextRoundBottonSeka = new NextRoundBottonSeka();
    this->raiseBottonSeka = new RaiseBottonSeka();
    this->restartBottonSeka = new RestartBottonSeka();
    this->passBottonSeka = new PassBottonSeka();

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

    bankMeText.setPosition(5, 400);
    bankThisGameText.setPosition(20, SCREEN_HEIGHT/2 - 50);

    Sprite help;
    Texture helpt;
    helpt.loadFromFile("img/help2.png");
    help.setTexture(helpt);
    help.setPosition(0, 0);


    sf::Font font;
    font.loadFromFile("fonts/times.ttf");
    bankMeText.setFont(font);
    bankOpponentText.setFont(font);
    betMeText.setFont(font);
    betOpponentText.setFont(font);
    bankThisGameText.setFont(font);

    helpText.setCharacterSize(16);
    helpText.setPosition(750, 10);

    font.loadFromFile("fonts/times.ttf");
    helpText.setFont(font);
    helpText.setString("Press TAB to HELP");
    for(int i = 0; i < 5; i++)
    {
        betText[i].setFont(font);
    }


       sf::Text aiPass;
       aiPass.setCharacterSize(40);
       aiPass.setPosition( 700, 20);
        sf::Font testFont;
        testFont.loadFromFile("fonts/times.ttf");
        aiPass.setFont(testFont);
       aiPass.setString("AI PASS");





    while (this->win->isOpen())
    {
        Event event;
        while (this->win->pollEvent(event))
        {
            if (event.type == Event::Closed)
                this->win->close();
                        if (event.type == Event::KeyPressed)
            {
                if ((event.key.code == Keyboard::Tab))
                {
                    if(!inHelp)
                        {inHelp = true;
                        continue;}
                    if(inHelp)
                        inHelp = false;


                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                                        if(inHelp == false){
                    if(endGame == false){
                    if (nextBottonSeka->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                            nextBetMeDo();

                    if (passBottonSeka->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                            passDo();



                    if (revealBottonSeka->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                        {
                            revealDo();
                            this->inRound = false;
                        }

                    if (raiseBottonSeka->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                            raiseDo();

                    if (nextRoundBottonSeka->isPressed(event.mouseButton.x, event.mouseButton.y))
                        nextRoundDo();
                    }
                if (restartBottonSeka->isPressed(event.mouseButton.x, event.mouseButton.y))
                        restartDo();
                }
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


        if (this->bankMe<=0)
            {
                            this->revealDo();

                this ->endGame = true;
        this->win->draw(lose);
            }


        if (this->bankOpponent<=0)
        {
            this->revealDo();
                this ->endGame = true;
                this->win->draw(winn);
        }


            this->win->draw(bankMeText);
        this->win->draw(bankOpponentText);
        this->win->draw(bankThisGameText);
        this->win->draw(betMeText);
        this->win->draw(betOpponentText);

        //this->win->draw(aiPass);
        for (int i = 0; i < 5; i++)
            win->draw(betText[i]);
        this->win->draw(restartBottonSeka->sprite);



        if(!endGame){
                if(inRound){
        this->win->draw(revealBottonSeka->sprite);
        this->win->draw(passBottonSeka->sprite);
        this->win->draw(raiseBottonSeka->sprite);
        //this->win->draw(repeatBottonSeka->sprite);
        this->win->draw(nextBottonSeka->sprite);

        }
                this->win->draw(nextRoundBottonSeka->sprite);
        }
        if(inHelp== true)
            this->win->draw(help);
            this->win->draw(helpText);
        this->win->display();
    }
}
void SecondGame::refreshText()
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
    betMeText.setString(  "+"+ ss.str());

    ss.str("");

    ss.clear();
    ss << betOpponent;
    betOpponentText.setString( "+"+ ss.str());





}

