#include "Game.h"
#include <sstream>
#include <iostream>


bool counter;
Game::Game(RenderWindow* winInput)
{
    this->win = winInput;
    //int bank;
    deck = new Deck();
    size1 = 0;
    size2 = 0;
    size3 = 0;
    size4 = 0;
}

void Game::deck1Accept()
{
    pair <int,int> iterCard0;
    pair <int,int> iterCard1;

    iterCard0 = deck0.front();
    iterCard1 = deck1[size1];
    if((iterCard1.first == iterCard0.first) && (iterCard1.second == (int) iterCard0.second - 1))
    {
        size1++;
        deck1[size1] = iterCard0;

        deck0.pop_front();
    }
    else
    {
        deck0.pop_front();
        deck0.push_back(iterCard0);
    }
    iterCard0 = deck0.front();
    iterCard1 = deck1[size1];

    cardTexture0.loadFromFile("img/finish_cards_sheet.png");
    deckSprite0.setTexture(cardTexture0);
    deckSprite0.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard0.second, (float)615/5 * (int)iterCard0.first, (float)1027/13, (float)615/5 ));


    cardTexture1.loadFromFile("img/finish_cards_sheet.png");
    deckSprite1.setTexture(cardTexture1);
    deckSprite1.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard1.second, (float)615/5 * (int)iterCard1.first, (float)1027/13, (float)615/5 ));

}

void Game::deck2Accept()
{
    pair <int,int> iterCard0;
    pair <int,int> iterCard1;

    iterCard0 = deck0.front();
    iterCard1 = deck2[size2];
    if((iterCard1.first == iterCard0.first) && (iterCard1.second == (int) iterCard0.second - 1))
    {
        size2++;
        deck2[size2] = iterCard0;

        deck0.pop_front();
    }
    else
    {
        deck0.pop_front();
        deck0.push_back(iterCard0);
    }
    iterCard0 = deck0.front();
    iterCard1 = deck2[size2];

    cardTexture0.loadFromFile("img/finish_cards_sheet.png");
    deckSprite0.setTexture(cardTexture0);
    deckSprite0.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard0.second, (float)615/5 * (int)iterCard0.first, (float)1027/13, (float)615/5 ));


    cardTexture2.loadFromFile("img/finish_cards_sheet.png");
    deckSprite2.setTexture(cardTexture2);
    deckSprite2.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard1.second, (float)615/5 * (int)iterCard1.first, (float)1027/13, (float)615/5 ));

}


void Game::deck3Accept()
{
    pair <int,int> iterCard0;
    pair <int,int> iterCard1;

    iterCard0 = deck0.front();
    iterCard1 = deck3[size3];
    if((iterCard1.first == iterCard0.first) && (iterCard1.second == (int) iterCard0.second - 1))
    {
        size3++;
        deck3[size3] = iterCard0;

        deck0.pop_front();
    }
    else
    {
        deck0.pop_front();
        deck0.push_back(iterCard0);
    }
    iterCard0 = deck0.front();
    iterCard1 = deck3[size3];

    cardTexture0.loadFromFile("img/finish_cards_sheet.png");
    deckSprite0.setTexture(cardTexture0);
    deckSprite0.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard0.second, (float)615/5 * (int)iterCard0.first, (float)1027/13, (float)615/5 ));


    cardTexture3.loadFromFile("img/finish_cards_sheet.png");
    deckSprite3.setTexture(cardTexture3);
    deckSprite3.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard1.second, (float)615/5 * (int)iterCard1.first, (float)1027/13, (float)615/5 ));

}

void Game::deck4Accept()
{
    pair <int,int> iterCard0;
    pair <int,int> iterCard1;

    iterCard0 = deck0.front();
    iterCard1 = deck4[size4];
    if((iterCard1.first == iterCard0.first) && (iterCard1.second == (int) iterCard0.second - 1))
    {
        size4++;
        deck4[size4] = iterCard0;

        deck0.pop_front();
    }
    else
    {
        deck0.pop_front();
        deck0.push_back(iterCard0);
    }
    iterCard0 = deck0.front();
    iterCard1 = deck4[size4];

    cardTexture0.loadFromFile("img/finish_cards_sheet.png");
    deckSprite0.setTexture(cardTexture0);
    deckSprite0.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard0.second, (float)615/5 * (int)iterCard0.first, (float)1027/13, (float)615/5 ));


    cardTexture4.loadFromFile("img/finish_cards_sheet.png");
    deckSprite4.setTexture(cardTexture4);
    deckSprite4.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard1.second, (float)615/5 * (int)iterCard1.first, (float)1027/13, (float)615/5 ));

}

void Game::missedClick()
{
    pair <int,int> iterCard0;
    iterCard0 = deck0.front();
    deck0.pop_front();
    deck0.push_back(iterCard0);
    iterCard0 = deck0.front();

    cardTexture0.loadFromFile("img/finish_cards_sheet.png");
    deckSprite0.setTexture(cardTexture0);
    deckSprite0.setTextureRect(sf::IntRect((float)1027/13 * (int)iterCard0.second, (float)615/5 * (int)iterCard0.first, (float)1027/13, (float)615/5 ));

}
void Game::restartGame()
{
    memset(deck1, 0, sizeof(deck1));
    memset(deck2, 0, sizeof(deck2));
    memset(deck3, 0, sizeof(deck3));
    memset(deck4, 0, sizeof(deck4));
  deck0.clear();
    this->deck->putRandom();

    size1 = 0;
    size2 = 0;
    size3 = 0;
    size4 = 0;
    Card iterCard;
    pair<int,int> iterPair;

    for (int i = 0; i < 48; i++)
    {

        iterCard = deck->getCard();
        iterPair.first = iterCard.getColorIdentifier();
        iterPair.second = iterCard.getValueIdentifier();
        deck0.push_front(iterPair);
    }
    iterPair.first = 0;
    iterPair.second = 0;
    this->deck1[0] = iterPair;

    iterPair.first = 1;
    iterPair.second = 0;
    this->deck2[0] = iterPair;

    iterPair.first = 2;
    iterPair.second = 0;
    this->deck3[0] = iterPair;

    iterPair.first = 3;
    iterPair.second = 0;
    this->deck4[0] = iterPair;

    iterPair = deck0.front();
    cardTexture0.loadFromFile("img/finish_cards_sheet.png");
    deckSprite0.setTexture(cardTexture0);
    deckSprite0.setTextureRect(sf::IntRect((float)1027/13 * (int)iterPair.second, (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));

    cardTexture1.loadFromFile("img/finish_cards_sheet.png");
    deckSprite1.setTexture(cardTexture1);
    deckSprite1.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (0), (float)1027/13, (float)615/5 ));

    cardTexture2.loadFromFile("img/finish_cards_sheet.png");
    deckSprite2.setTexture(cardTexture2);
    deckSprite2.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (1), (float)1027/13, (float)615/5 ));

    cardTexture3.loadFromFile("img/finish_cards_sheet.png");
    deckSprite3.setTexture(cardTexture3);
    deckSprite3.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (2), (float)1027/13, (float)615/5 ));

    cardTexture4.loadFromFile("img/finish_cards_sheet.png");
    deckSprite4.setTexture(cardTexture4);
    deckSprite4.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (3), (float)1027/13, (float)615/5 ));

}
void Game::start()
{

    this->deck = new Deck();
    this->deck->putRandom();
    Card iterCard;
    pair<int,int> iterPair;

    for (int i = 0; i < 48; i++)
    {

        iterCard = deck->getCard();
        iterPair.first = iterCard.getColorIdentifier();
        iterPair.second = iterCard.getValueIdentifier();
        deck0.push_front(iterPair);
    }
    /*    for (int i = 0; i < 48; i++)
    {


        iterPair = deck0.front();
        printf("first : %i,    second : %i\n", iterPair.first, iterPair.second);
        deck0.pop_front();
    }*/
    iterPair.first = 0;
    iterPair.second = 0;
    this->deck1[0] = iterPair;

    iterPair.first = 1;
    iterPair.second = 0;
    this->deck2[0] = iterPair;

    iterPair.first = 2;
    iterPair.second = 0;
    this->deck3[0] = iterPair;

    iterPair.first = 3;
    iterPair.second = 0;
    this->deck4[0] = iterPair;



    iterPair = deck0.front();

    cardTexture0.loadFromFile("img/finish_cards_sheet.png");
    deckSprite0.setTexture(cardTexture0);
    deckSprite0.setTextureRect(sf::IntRect((float)1027/13 * (int)iterPair.second, (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));

    cardTexture1.loadFromFile("img/finish_cards_sheet.png");
    deckSprite1.setTexture(cardTexture1);
    deckSprite1.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (0), (float)1027/13, (float)615/5 ));

    cardTexture2.loadFromFile("img/finish_cards_sheet.png");
    deckSprite2.setTexture(cardTexture2);
    deckSprite2.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (1), (float)1027/13, (float)615/5 ));

    cardTexture3.loadFromFile("img/finish_cards_sheet.png");
    deckSprite3.setTexture(cardTexture3);
    deckSprite3.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (2), (float)1027/13, (float)615/5 ));

    cardTexture4.loadFromFile("img/finish_cards_sheet.png");
    deckSprite4.setTexture(cardTexture4);
    deckSprite4.setTextureRect(sf::IntRect((float)1027/13 * (0), (float)615/5 * (3), (float)1027/13, (float)615/5 ));





    deckSprite1.setPosition(100, 100);
    deckSprite2.setPosition(300, 100);
    deckSprite3.setPosition(100, 330);
    deckSprite4.setPosition(300, 330);

    deckSprite0.setPosition(600, 215);

    deckSprite1.scale(sf::Vector2f(1.4f, 1.4f));
    deckSprite2.scale(sf::Vector2f(1.4f, 1.4f));
    deckSprite3.scale(sf::Vector2f(1.4f, 1.4f));
    deckSprite4.scale(sf::Vector2f(1.4f, 1.4f));

    deckSprite0.scale(sf::Vector2f(1.4f, 1.4f));

    Sprite background;
    Texture backTexture;
    backTexture.loadFromFile("img/wood-texture.jpg");
    background.setTexture(backTexture);
    background.setPosition(0, 0);
    //background.setScale((float)SCREEN_WIDTH/400, (float)SCREEN_HEIGHT/ 300);


//U WIN U LOSE PICS

    Sprite lose;
    Texture uLose;
    uLose.loadFromFile("img/restart.png");
    lose.setTexture(uLose);
    lose.setPosition(765, 444);

    Sprite winn;
    Texture uWin;
    uWin.loadFromFile("img/uWin.jpg");
    winn.setTexture(uWin);
    winn.setPosition(595, 185);


    Sprite both;
    Texture theBoth;
    theBoth.loadFromFile("img/both.png");
    both.setTexture(theBoth);
    both.setPosition(600, 200);


    pair<int,int> endPair;
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

                    if ((event.mouseButton.x > 100) && ( event.mouseButton.x < 180) && (event.mouseButton.y > 100) && (event.mouseButton.y < 272))

                    {

                        deck1Accept();
                    }

                    if ((event.mouseButton.x > 300) && ( event.mouseButton.x < 380) && (event.mouseButton.y > 100) && (event.mouseButton.y < 272))

                    {

                        deck2Accept();
                    }

                    if ((event.mouseButton.x > 100) && ( event.mouseButton.x < 180) && (event.mouseButton.y > 330) && (event.mouseButton.y < 502))

                    {

                        deck3Accept();
                    }

                    if ((event.mouseButton.x > 300) && ( event.mouseButton.x < 380) && (event.mouseButton.y > 330) && (event.mouseButton.y < 502))

                    {

                        deck4Accept();
                    }

                    if ((event.mouseButton.x > 765) && ( event.mouseButton.x < 900) && (event.mouseButton.y > 444) && (event.mouseButton.y < 533))

                    {
                        restartGame();

                    }
                    else if(!((event.mouseButton.x > 100) && ( event.mouseButton.x < 180) && (event.mouseButton.y > 100) && (event.mouseButton.y < 272)) && !((event.mouseButton.x > 300) && ( event.mouseButton.x < 380) && (event.mouseButton.y > 100) && (event.mouseButton.y < 272)) && !((event.mouseButton.x > 100) && ( event.mouseButton.x < 180) && (event.mouseButton.y > 330) && (event.mouseButton.y < 502))&& !((event.mouseButton.x > 300) && ( event.mouseButton.x < 380) && (event.mouseButton.y > 330) && (event.mouseButton.y < 502))&& !((event.mouseButton.x > 765) && ( event.mouseButton.x < 900) && (event.mouseButton.y > 444) && (event.mouseButton.y < 533)))
                    {
                        missedClick();
                        //deck1Accept();
                        // deck2Accept();
                        //deck3Accept();
                        // deck4Accept();
                    }

                }
            }

            this->win->clear();
            this->win->draw(background);

            this->win->draw(deckSprite1);
            this->win->draw(deckSprite2);
            this->win->draw(deckSprite3);
            this->win->draw(deckSprite4);
            this->win->draw(deckSprite0);

            endPair = deck0.front();
            if(endPair.first == 0 && endPair.second == 0)
                this->win->draw(winn);

            this->win->draw(lose);

            this->win->display();

        }
    }
}
