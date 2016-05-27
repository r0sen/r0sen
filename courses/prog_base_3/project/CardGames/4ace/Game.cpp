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
    lose.setPosition(600, 200);

    Sprite winn;
    Texture uWin;
    uWin.loadFromFile("img/win.png");
    winn.setTexture(uWin);
    winn.setPosition(600, 200);


    Sprite both;
    Texture theBoth;
    theBoth.loadFromFile("img/both.png");
    both.setTexture(theBoth);
    both.setPosition(600, 200);

    // BUTTONS
    this->nextBotton = new NextBotton();
//    this->endButton = new EndBotton();
    //restartBotton = new RestartBotton();

    this->revealBotton = new RevealBotton();
    this->nextBotton = new NextBotton();
    //this->repeatBotton = new RepeatBotton();
    this->nextRoundBotton = new NextRoundBotton();
    this->raiseBotton = new RaiseBotton();
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
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if(endGame == false){
                    if (nextBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                            nextBetMeDo();

                    if (passBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                            passDo();



                    if (revealBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                        {
                            revealDo();
                            this->inRound = false;
                        }

                    if (raiseBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        if(inRound)
                            raiseDo();

                    if (nextRoundBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        nextRoundDo();
                    }
                if (restartBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                        restartDo();
                }
            }
        }

        this->win->clear();

        //this->win->draw(raiseBotton->sprite);
        //this->win->draw(repeatBotton->sprite);
        //this->win->draw(nextBotton->sprite);
        this->win->display();
    }
}
