#include "Game.h"
#include <sstream>
#include <iostream>



Game::Game(RenderWindow* winInput)
{
    this->win = winInput;
    this->rateMe = 0;
    this->rateOpponent = 0;
    this->countSteps = 2;
    this->finishedGame = false;
    this->winMe = false;
    this->winOpponent = false;
    this->both = false;

}



void Game::start()
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
    theBoth.loadFromFile("img/win.png");
    both.setTexture(theBoth);
    both.setPosition(200, 200);

    // BUTTONS
    this->nextButton = new NextBotton();
    this->endButton = new EndBotton();
    this->restartButton = new RestartBotton();


    for (int i = 0; i < 5; i++)
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
                    if (nextButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(this->finishedGame == false)
                        {
                            this->nextRound();

                        }

                    if (endButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(this->finishedGame == false)
                            this->testForWinFinal();

                    if (restartButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                    {
                        //this->win = winInput;
                        nextDistribution();
                    }
                    //this->win->close(); // @TODO: finish game
                }
            }
        }


        this->win->clear();
        this->win->draw(background);

        for (int i = 0; i <= this->countSteps; i++)
        {
            if (me[i]->visible)
                this->win->draw(me[i]->sprite);

            if (opponent[i]->visible)
                this->win->draw(opponent[i]->sprite);
        }

        if(this->winMe)
        {
            this->win->draw(winn);
            this->finishedGame = true;
        }
        if(this->winOpponent)
        {
            this->win->draw(lose);
            this->finishedGame = true;
        }
        if(this->both)
        {
            this->win->draw(both);
            this->finishedGame = true;
        }
        if(finishedGame)
        {
            opponent[0]->setTexture();
            this->win->draw(opponent[0]->sprite);
        }
        this->win->draw(nextButton->sprite);
        this->win->draw(endButton->sprite);
        this->win->draw(restartButton->sprite);
        this->win->display();
    }
}


void Game::nextRound()
{
    this->rateMe = 0;
    this->rateOpponent = 0;
    if(this->countSteps<5)
    {
        for(int i = 0; i<= this->countSteps; i++)
        {


            this->rateMe +=this->me[i]->getValueIdentifier() + 1;

            if(this->me[i]->getValueIdentifier()==12)
                this->rateMe = this->rateMe - 3;
            if(this->me[i]->getValueIdentifier()==11)
                this->rateMe = this->rateMe - 2;
            if(this->me[i]->getValueIdentifier()==10)
                this->rateMe = this->rateMe - 1;
        }
        for(int i = 0; i<= this->countSteps; i++)
        {
            this->rateOpponent =this->rateOpponent + this->opponent[i]->getValueIdentifier() + 1;
            if(this->opponent[i]->getValueIdentifier()==12)
                this->rateOpponent = this->rateOpponent - 3;
            if(this->opponent[i]->getValueIdentifier()==11)
                this->rateOpponent = this->rateOpponent - 2;
            if(this->opponent[i]->getValueIdentifier()==10)
                this->rateOpponent = this->rateOpponent - 1;
        }
        for(int i = 0; i<= this->countSteps; i++)
        {
            this->me[i]->visible = true;
            this->opponent[i]->visible = true;
        }
        this->countSteps++;
        printf("rateMe = %i\n", this->rateMe);
        printf("rateOpponent = %i\n", this->rateOpponent);
        this->testForWinSkip();
    }

}

void Game::testForWinFinal()
{
    this->countSteps--;
    this->nextRound();
    if (this->rateMe > this->rateOpponent)
        this->winMe = true;
    if (this->rateMe < this->rateOpponent)
        this->winOpponent = true;
    this->finishedGame = true;

}
void Game::testForWinSkip()
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
        this->finishedGame = true;

}


void Game::nextDistribution()
{
    //free(this);
    this->rateMe = 0;
    this->rateOpponent = 0;
    this->countSteps = 2;
    this->finishedGame = false;
    this->winMe = false;
    this->winOpponent = false;
    this->both = false;
    deck->putRandom();
        for (int i = 0; i < 5; i++)
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
