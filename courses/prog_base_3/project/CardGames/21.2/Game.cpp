#include "Game.h"
#include <sstream>
#include <iostream>



Game::Game(RenderWindow* winInput)
{
    this->win = winInput;
    this->rateMe = 0;
    this->rateOpponent = 0;
    this->countSteps = 0;
    this->finishedGame = false;
    this->winMe = false;
    this->winOpponent = false;

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

    // BUTTONS
    this->nextButton = new NextBotton();
    this->endButton = new EndBotton();


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
                        this->nextRound();
                    if (endButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(this->finishedGame == false)
                        this->testForWinFinal();
                        //this->win->close(); // @TODO: finish game
                }
            }
        }


        //this->win->clear();
        this->win->draw(background);

        for (int i = 0; i <= countSteps; i++)
        {
            if (me[i]->visible)
                this->win->draw(me[i]->sprite);

            if (opponent[i]->visible)
                this->win->draw(opponent[i]->sprite);
        }
        this->win->draw(nextButton->sprite);
        this->win->draw(endButton->sprite);
        this->win->display();
    }
}


void Game::nextRound()
{
    if(countSteps<5)
    {
        for(int i = 0; i<= this->countSteps; i++)
        {
            this->rateMe+=this->me[i]->getValueIdentifier();
        }

        for(int i = 0; i<= this->countSteps; i++)
        {
            this->rateOpponent+=this->opponent[i]->getValueIdentifier();
        }


        for(int i = 0; i<= this->countSteps; i++)
        {
            this->me[i]->visible = true;
            this->opponent[i]->visible = true;
        }

        countSteps++;
        if(this->rateMe > this->rateOpponent)
            printf("U WINNING!!!!\n");
        if(this->rateMe < this->rateOpponent)
            printf("U LOOSING!!!!\n");
            this->testForWinSkip();
    }

}

void Game::testForWinFinal()
{

    if (this->rateMe > this->rateOpponent)
        printf("\nU WIN!!!!\n");
    if((this->rateMe == 21)&&(this->rateOpponent != 21))
        printf("\nU WIN!!!!\n");
    if((this->rateOpponent == 21)&&(this->rateMe != 21))
        printf("\nU LOOSE!!!!\n");
    if(this->rateMe > 21)
        printf("\nU LOOSE!!!!\n");
    if((this->rateOpponent > 21)&&(this->rateMe <= 21))
        printf("\nU WIN!!!!\n");
    if (this->rateMe < this->rateOpponent)
        printf("\nU LOOSE!!!!\n");
        this->finishedGame = true;

}
void Game::testForWinSkip()
{

    if((this->rateMe == 21)&&(this->rateOpponent != 21))
        this->winMe = true;
    if((this->rateOpponent == 21)&&(this->rateMe != 21))
        this->winOpponent = true;
    if((this->rateMe > 21))
        this->winOpponent = true;
    if((this->rateOpponent > 21)&&(this->rateMe <= 21))
        this->winMe = true;
        this->finishedGame = true;

}

