#include "Game.h"
#include <sstream>
#include <iostream>


bool counter;
Game::Game(RenderWindow* winInput)
{
    this->win = winInput;
    //int bank;
    deck = new Deck();
    pointsTotal = 0;
    lastMe = false;
    lastOpponent = true;

    winMe = false;
    winOpponent = false;

}
pair<int,int> Game::cardChoice(int x, int y)
{
    int clicked;
    bool isclicked;
    for(int i = 0; i<me.size(); i++)
    {
        if ((x < (100 + 18*(i+1))) && (x > (100 + 18*i)) && (y> 370) && (y< 542))
        {
            clicked = i;
            isclicked = true;
            break;
        }

    }
    //if((x<(100 + (me.size()-1) * 18 + 62)) && (x>(100 + (me.size()-1) * 18)))
    // clicked =me.size()-1;
    if(isclicked == true)
    {
        //me.erase(clicked);
        pair<int,int> iterPair;
        pair<int,int> selectPair;
        int selectVal;
        for(int i = 0; i<= me.size(); i++)
        {
            if(i!=(clicked))
            {
                iterPair = me.front();


                me.pop_front();
                me.push_back(iterPair);

            }
            else
            {
                selectPair = me.front();
                me.pop_front();
            }
        }

        for(int i = 0; i< me.size(); i++)
        {
            iterPair = me.front();
            texturesMe[i].loadFromFile("img/finish_cards_sheet.png");

            spritesMe[i].setTexture(texturesMe[i]);
            spritesMe[i].setTextureRect(sf::IntRect((float)1027/13 * (int)iterPair.second, (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));
            spritesMe[i].setPosition(100 + i *18, 370);

            me.pop_front();
            me.push_back(iterPair);
        }
        /*     selectVal = selectPair.second + 1;
             if((selectVal >10) && (selectVal<14))
             {
                 selectVal = 10;
                 selectPair.second = 9;
             }
             selectPair.second++;*/
        //printf("select : %i\n", selectPair.second);

        return selectPair;
    }

}

void Game::pushSelectPair(pair<int,int> selectPair)
{
    deck0.push_front(selectPair);
    pair<int,int> iterPair;
    int addPoints = 0;
    if((selectPair.second >9) && (selectPair.second<13))
    {

        addPoints = selectPair.second - 9;
    }
    else
    {
        addPoints = selectPair.second;
    }
    addPoints++;
    pointsTotal += addPoints;
    printf("ME selectPair.second : %i\n",selectPair.second);
    iterPair = deck0.front();
    deck0Texture.loadFromFile("img/finish_cards_sheet.png");

    deck0Sprite.setTexture(deck0Texture);
    deck0Sprite.setTextureRect(sf::IntRect((float)1027/13 * (int)iterPair.second, (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));
    deck0Sprite.setPosition(400, 180);
    lastMe = true;
    lastOpponent = false;
    testForWin();
    aiTurn();
    printf("pointsTotal : %i\n",pointsTotal);
}
void Game::aiPushSelectPair(pair<int,int> selectPair)
{
    deck0.push_front(selectPair);
    pair<int,int> iterPair;
    int addPoints = 0;
    if((selectPair.second >9) && (selectPair.second<13))
    {

        addPoints = selectPair.second - 9;
    }
    else
    {
        addPoints = selectPair.second;
    }
    addPoints++;
    pointsTotal += addPoints;

    iterPair = deck0.front();
    deck0Texture.loadFromFile("img/finish_cards_sheet.png");

    deck0Sprite.setTexture(deck0Texture);
    deck0Sprite.setTextureRect(sf::IntRect((float)1027/13 * (int)(iterPair.second), (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));
    deck0Sprite.setPosition(400, 180);
    lastMe = false;
    lastOpponent = true;

    /**!!!!!!!!!!!!!!!!ddddddddddddddddddddddddddddddddddd!!!!!!!!!!!!!!!**/



    for(int i = 0; i< opponent.size(); i++)
    {
        iterPair = opponent.front();
        texturesOpponent[i].loadFromFile("img/finish_cards_sheet.png");

        spritesOpponent[i].setTexture(texturesOpponent[i]);
        spritesOpponent[i].setTextureRect(sf::IntRect((float)1027/13 * (int)iterPair.second, (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));
        //spritesOpponent[i].setPosition(100 + i *18, 370);

        opponent.pop_front();
        opponent.push_back(iterPair);
    }
}





void Game::aiTurn()
{
    bool turnDone = false;
    if(pointsTotal<80)
    {
        pair<int,int> iterPair;
        pair<int,int> selectPair;
        int maxVal = 0;
        int maxIndex = 0;
        int selectVal;
        bool saveForFuture1 = false;
        bool saveForFuture2;
        for(int i = 0; i< opponent.size(); i++)
        {
            iterPair = opponent.front();
            opponent.pop_front();
            opponent.push_back(iterPair);
            if(iterPair.second == 9 || iterPair.second == 8)
            {
                //if(saveForFuture1 = false)
                //{
                // saveForFuture1 = true;
                continue;

                //}
            }
            if(maxVal< iterPair.second)
            {
                maxVal=iterPair.second;
                maxIndex = i;
            }

        }

        for(int i = 0; i<= opponent.size(); i++)
        {

            if(i!=maxIndex)
            {
                iterPair = opponent.front();
                opponent.pop_front();
                opponent.push_back(iterPair);

            }
            else
            {
                selectPair = opponent.front();
                opponent.pop_front();
            }
        }


        printf("AI selectPair.second : %i\n",selectPair.second);

        aiPushSelectPair(selectPair);
        turnDone = true;
    }

    if(((100 - pointsTotal )== 11 ) && turnDone == false )
    {
        int toEnd = 10;
        pair<int,int> iterPair;
        pair<int,int> selectPair;
        //int minVal = 11;
        int endIndex = 0;
        //int selectVal;
        // bool saveForFuture1 = false;
        //bool saveForFuture2;
        for(int i = 0; i< opponent.size(); i++)
        {
            iterPair = opponent.front();
            opponent.pop_front();
            opponent.push_back(iterPair);

            if(toEnd == (iterPair.second + 1))
            {

                endIndex = i;
                turnDone = true;

                break;
            }

        }

        for(int i = 0; i<= opponent.size(); i++)
        {

            if(i!=endIndex)
            {
                iterPair = opponent.front();
                opponent.pop_front();
                opponent.push_back(iterPair);

            }
            else
            {
                selectPair = opponent.front();
                opponent.pop_front();
            }
        }


        printf("AI selectPair.second : %i\n",selectPair.second);

        aiPushSelectPair(selectPair);
    }
    if(((100 - pointsTotal )<= 10 ) && turnDone == false )
    {
        int toEnd = 100 - pointsTotal;
        pair<int,int> iterPair;
        pair<int,int> selectPair;
        //int minVal = 11;
        int endIndex = 0;
        //int selectVal;
        // bool saveForFuture1 = false;
        //bool saveForFuture2;
        for(int i = 0; i< opponent.size(); i++)
        {
            iterPair = opponent.front();
            opponent.pop_front();
            opponent.push_back(iterPair);

            if(toEnd == (iterPair.second + 1))
            {

                endIndex = i;
                turnDone = true;

                break;
            }

        }

        for(int i = 0; i<= opponent.size(); i++)
        {

            if(i!=endIndex)
            {
                iterPair = opponent.front();
                opponent.pop_front();
                opponent.push_back(iterPair);

            }
            else
            {
                selectPair = opponent.front();
                opponent.pop_front();
            }
        }


        printf("AI selectPair.second : %i\n",selectPair.second);

        aiPushSelectPair(selectPair);
    }
    if(pointsTotal>=80 && turnDone == false)
    {
        pair<int,int> iterPair;
        pair<int,int> selectPair;
        int minVal = 11;
        int minIndex = 0;
        int selectVal;
        // bool saveForFuture1 = false;
        //bool saveForFuture2;
        for(int i = 0; i< opponent.size(); i++)
        {
            iterPair = opponent.front();
            opponent.pop_front();
            opponent.push_back(iterPair);

            if(minVal> iterPair.second)
            {
                minVal=iterPair.second;
                minIndex = i;
            }

        }

        for(int i = 0; i<= opponent.size(); i++)
        {

            if(i!=minIndex)
            {
                iterPair = opponent.front();
                opponent.pop_front();
                opponent.push_back(iterPair);

            }
            else
            {
                selectPair = opponent.front();
                opponent.pop_front();
            }
        }


        printf("AI selectPair.second : %i\n",selectPair.second);

        aiPushSelectPair(selectPair);
        turnDone = true;
    }

}
void Game::testForWin()
{
    if(pointsTotal == 100)
    {
        if(lastMe)
            winMe = true;
        if(lastOpponent)
            winOpponent = true;
    }

    if(pointsTotal>100)
    {
        if(lastMe)
            winOpponent = true;
        if(lastOpponent)
            winMe = true;
    }

}









void Game::start()
{

    this->deck = new Deck();
    this->deck->putRandom();
    Card iterCard;
    pair<int,int> iterPair;
    deck0Sprite.scale(sf::Vector2f(1.2f, 1.2f));
    for (int i = 0; i < 24; i++)
    {

        iterCard = deck->getCard();
        iterPair.first = iterCard.getColorIdentifier();
        iterPair.second = iterCard.getValueIdentifier();
        me.push_front(iterPair);

        iterCard = deck->getCard();
        iterPair.first = iterCard.getColorIdentifier();
        iterPair.second = iterCard.getValueIdentifier();
        opponent.push_front(iterPair);
    }
    for(int i = 0; i< 24; i++)
    {
        iterPair = me.front();
        texturesMe[i].loadFromFile("img/finish_cards_sheet.png");

        spritesMe[i].setTexture(texturesMe[i]);
        spritesMe[i].setTextureRect(sf::IntRect((float)1027/13 * (int)iterPair.second, (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));
        spritesMe[i].setPosition(100 + i *18, 370);
        spritesMe[i].scale(sf::Vector2f(1.2f, 1.2f));
        me.pop_front();
        me.push_back(iterPair);
    }

    for(int i = 0; i< 24; i++)
    {
        iterPair = opponent.front();
        texturesOpponent[i].loadFromFile("img/finish_cards_sheet.png");

        spritesOpponent[i].setTexture(texturesOpponent[i]);
        spritesOpponent[i].setTextureRect(sf::IntRect((float)1027/13 * 0, (float)615/5 * 4, (float)1027/13, (float)615/5 ));
        spritesOpponent[i].setPosition(100 + i *18, 10);
        spritesOpponent[i].scale(sf::Vector2f(1.2f, 1.2f));
        opponent.pop_front();
        opponent.push_back(iterPair);
    }


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

    pair<int,int> selectPair;
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

                    selectPair = cardChoice(event.mouseButton.x, event.mouseButton.y);
                    pushSelectPair(selectPair);


                    // if ((event.mouseButton.x > 100) && ( event.mouseButton.x < 180) && (event.mouseButton.y > 100) && (event.mouseButton.y < 272))

                    //{


                    //}


                }
            }

            this->win->clear();
            this->win->draw(background);

            this->win->draw(lose);
            for(int i = 0; i< me.size(); i++)
            {
                this->win->draw(spritesMe[i]);
            }
            for(int i = 0; i< opponent.size(); i++)
            {
                this->win->draw(spritesOpponent[i]);
            }
            this->win->draw(deck0Sprite);
            this->win->display();

        }
    }
}
