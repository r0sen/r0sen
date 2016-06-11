#include "FirstGame.h"
#include <sstream>
#include <iostream>


//bool counter;
FirstGame::FirstGame(RenderWindow* winInput)
{
    this->win = winInput;
    this->rateMe = 0;
    this->rateOpponent = 0;
    this->countSteps = 2;
    this->countStepsMe = 2;
    this->countStepsOpponent = 2;
    this->finishedFirstGame = false;
    this->winMe = false;
    this->winOpponent = false;
    this->both = false;
    this->inHelp = false;

}



void FirstGame::start()
{


    this->deck = new Deck();
    deck->putRandom();
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
    this->nextButton = new NextBotton();
    this->endButton = new EndBotton();
    this->restartButton = new RestartBotton();


    for (int i = 0; i < 7; i++)
    {
        this->opponent[i] = new Card();
        *opponent[i] = deck->getCard();
        opponent[i]->sprite.setPosition(i * 100 + 190, 100);
        opponent[i]->setTexture();
        opponent[i]->visible = false;

        this->me[i] = new Card();
        *me[i] = deck->getCard();
        me[i]->sprite.setPosition(i * 100 + 190, 300);
        me[i]->setTexture();
        me[i]->visible = false;
    }
// put cards in start POSITION
    opponent[0]->texture.loadFromFile("img/finish_cards_sheet.png");
    opponent[0]->sprite.setTextureRect(sf::IntRect(0, (float) 492/1, (float)1027/13, (float)615/5 ));
    opponent[0]->sprite.setTexture(opponent[0]->texture);


    opponent[0]->visible = true;
    opponent[1]->visible = true;
    me[0]->visible = true;
    me[1]->visible = true;

    Sprite help;
    Texture helpt;
    helpt.loadFromFile("img/help1.png");
    help.setTexture(helpt);
    help.setPosition(0, 0);


    helpText.setCharacterSize(16);
    helpText.setPosition(750, 10);
    sf::Font font;
    font.loadFromFile("fonts/times.ttf");
    helpText.setFont(font);
    helpText.setString("Press TAB to HELP");
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
                    if (nextButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(this->finishedFirstGame == false)
                        {
                            this->nextRound();
                        }

                    if (endButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(this->finishedFirstGame == false)
                        {
                            bool c = false;

                            while(this->finishedFirstGame == false){
                                if(c == false)
                                    c = this->aiTurn();
                                    else
                                        this->testForWinFinal();

                            }
                            //this->testForWinFinal();
                        }

                    if (restartButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                    {
                        //this->win = winInput;
                        restartFirstGame();
                    }
                  }  //this->win->close(); // @TODO: finish FirstGame
                }
            }
        }


        this->win->clear();
        this->win->draw(background);

        for (int i = 0; i <5; i++)
        {
            if (me[i]->visible)
                this->win->draw(me[i]->sprite);

            if (opponent[i]->visible)
                this->win->draw(opponent[i]->sprite);
        }

        if(this->winMe)
        {
            this->win->draw(winn);
            this->finishedFirstGame = true;
        }
        if(this->winOpponent)
        {
            this->win->draw(lose);
            this->finishedFirstGame = true;
        }
        if(this->both)
        {
            this->win->draw(both);
            this->finishedFirstGame = true;
        }
        if(finishedFirstGame)
        {
            opponent[0]->setTexture();
            this->win->draw(opponent[0]->sprite);

        }


        this->win->draw(nextButton->sprite);
        this->win->draw(endButton->sprite);
        this->win->draw(restartButton->sprite);
                    if(inHelp== true)
            this->win->draw(help);
            this->win->draw(helpText);
        this->win->display();
    }
}


void FirstGame::nextRound()
{
    this->rateMeFn();
    this->countStepsMe++;
        for(int i = 0; i< this->countStepsMe; i++)
        {
            this->me[i]->visible = true;
        }





        this->aiTurn();
        for(int i = 0; i< this->countStepsOpponent; i++)
        {
            this->opponent[i]->visible = true;
        }


        printf("rateMe = %i\n", this->rateMe);
        printf("rateOpponent = %i\n", this->rateOpponent);
        this->testForWinSkip();
    }



void FirstGame::testForWinFinal()
{
    this->countStepsMe--;
    this->nextRound();
    if((this->rateMe == 21)&&(this->rateOpponent != 21))
        this->winMe = true;
    if((this->rateOpponent == 21)&&(this->rateMe != 21))
        this->winOpponent = true;
    if((this->rateMe > 21)&&(this->rateOpponent < 21))
        this->winOpponent = true;
    if((this->rateOpponent > 21)&&(this->rateMe < 21))
        this->winMe = true;
    if((this->rateOpponent > 21)&&(this->rateMe > 21))
        this->both = true;




    else{
    if ((this->rateMe > this->rateOpponent)&&((this->rateOpponent <= 21)&&(this->rateMe <= 21)))
        this->winMe = true;
    if ((this->rateMe < this->rateOpponent)&&((this->rateOpponent <= 21)&&(this->rateMe <= 21)))
        this->winOpponent = true;
    if (this->rateMe == this->rateOpponent)
        this->both = true;
    }



    if((this->winMe == true)||(this->winOpponent == true)||(this->both == true))
        this->finishedFirstGame = true;

}
void FirstGame::testForWinSkip()
{

    if((this->rateMe == 21)&&(this->rateOpponent != 21))
        this->winMe = true;
    if((this->rateOpponent == 21)&&(this->rateMe != 21))
        this->winOpponent = true;
    if((this->rateMe > 21)&&(this->rateOpponent < 21))
        this->winOpponent = true;
    if((this->rateOpponent > 21)&&(this->rateMe < 21))
        this->winMe = true;
    if((this->rateOpponent > 21)&&(this->rateMe > 21))
        this->both = true;

    if((this->winMe == true)||(this->winOpponent == true)||(this->both == true))
        this->finishedFirstGame = true;

}


void FirstGame::restartFirstGame()
{
    //free(this);
    this->countStepsOpponent = 2;
    this->countStepsMe = 2;
    this->rateMe = 0;
    this->rateOpponent = 0;
    this->countSteps = 2;
    this->finishedFirstGame = false;
    this->winMe = false;
    this->winOpponent = false;
    this->both = false;
    deck->putRandom();
    for (int i = 0; i < 7; i++)
    {
        //this->opponent[i] = new Card();
        *opponent[i] = deck->getCard();
        opponent[i]->sprite.setPosition(i * 100 + 190, 100);
        opponent[i]->setTexture();
        opponent[i]->visible = false;

        //this->me[i] = new Card();
        *me[i] = deck->getCard();
        me[i]->sprite.setPosition(i * 100 + 190, 300);
        me[i]->setTexture();
        me[i]->visible = false;
    }
// put cards in start POSITION
    opponent[0]->texture.loadFromFile("img/finish_cards_sheet.png");
    opponent[0]->sprite.setTextureRect(sf::IntRect(0, (float) 492/1, (float)1027/13, (float)615/5 ));
    opponent[0]->sprite.setTexture(opponent[0]->texture);

    //opponent[0]->~Card;
    opponent[0]->visible = true;
    opponent[1]->visible = true;
    me[0]->visible = true;
    me[1]->visible = true;

}

bool FirstGame::aiTurn()
{
    this->rateOpponentFn();
    this->rateMeFn();

    if(this->rateOpponent < 16)
    {
               this->countStepsOpponent++;
               this->rateOpponentFn();
               return false;

    }
return true;

}

void FirstGame::rateMeFn()
{


    if(this->countStepsMe<7)
    {
            this->rateMe = 0;
        for(int i = 0; i< this->countStepsMe; i++)
        {


            this->rateMe +=this->me[i]->getValueIdentifier() + 1;

            if(this->me[i]->getValueIdentifier()==12)
                this->rateMe = this->rateMe - 3;
            if(this->me[i]->getValueIdentifier()==11)
                this->rateMe = this->rateMe - 2;
            if(this->me[i]->getValueIdentifier()==10)
                this->rateMe = this->rateMe - 1;
        }


}
}



    void FirstGame::rateOpponentFn(){

    if(this->countStepsOpponent<7)
    {
        rateOpponent = 0;
        for(int i = 0; i< this->countStepsOpponent; i++)
        {
            this->rateOpponent =this->rateOpponent + this->opponent[i]->getValueIdentifier() + 1;
            if(this->opponent[i]->getValueIdentifier()==12)
                this->rateOpponent = this->rateOpponent - 3;
            if(this->opponent[i]->getValueIdentifier()==11)
                this->rateOpponent = this->rateOpponent - 2;
            if(this->opponent[i]->getValueIdentifier()==10)
                this->rateOpponent = this->rateOpponent - 1;
        }



    }
    }
