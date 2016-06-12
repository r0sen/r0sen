#include "FourthGame.h"
#include <sstream>
#include <iostream>
#include <windows.h>
#include <SFML/Audio.hpp>
//bool counter;
FourthGame::FourthGame(RenderWindow* winInput)
{
    this->win = winInput;
    deck = new Deck100();
    pointsTotal = 0;
    lastMe = false;
    lastOpponent = true;
    winMe = false;
    winOpponent = false;
    sizeCallBack = 0;
    inHelp = false;

}



void FourthGame::this_is_callback_fn(bool lastMy, bool lastOpp, int pointsGame)
{
    if((lastMy == true) && (lastOpp == false ) && (pointsGame == 100))
    {
        this->winMe = true;
        this->winOpponent = false;
    }


    if((lastMy == false) && (lastOpp == true ) && (pointsGame == 100))
    {
        this->winMe = false;
        this->winOpponent = true;
    }
    if((lastMy == false) && (lastOpp == true ) && (pointsGame > 100))
    {
        this->winMe = true;
        this->winOpponent = false;
    }

    if((lastMy == true) && (lastOpp == false ) && (pointsGame > 100))
    {
        this->winMe = false;
        this->winOpponent = true;
    }


}


pair<int,int> FourthGame::cardChoice(int x, int y)
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

void FourthGame::pushSelectPair(pair<int,int> selectPair)
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
    mePush = true;
    drawDeck0 = true;
    printf("pointsTotal : %i\n",pointsTotal);
}
void FourthGame::aiPushSelectPair(pair<int,int> selectPair)
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


    /*
        for(int i = 0; i< opponent.size(); i++)
        {
            iterPair = opponent.front();
            texturesOpponent[i].loadFromFile("img/finish_cards_sheet.png");

            spritesOpponent[i].setTexture(texturesOpponent[i]);
            spritesOpponent[i].setTextureRect(sf::IntRect((float)1027/13 * (int)iterPair.second, (float)615/5 * (int)iterPair.first, (float)1027/13, (float)615/5 ));
            //spritesOpponent[i].setPosition(100 + i *18, 370);

            opponent.pop_front();
            opponent.push_back(iterPair);
        }*/
}





void FourthGame::aiTurn()
{
    bool turnDone = false;
    if(pointsTotal<80 && (turnDone == false))
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

    if(((100 - pointsTotal )== 11 ) && (turnDone == false) )
    {
        int toEnd = 9;
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
    if(((100 - pointsTotal )<= 10 ) && (turnDone == false ))
    {
        int toEnd = 100 - pointsTotal -1;
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

            if(toEnd == iterPair.second )
            {

                endIndex = i;
                turnDone = true;

                //break;
            }

        }
        if (turnDone == false)
            goto nextStep;
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
nextStep:

    if(pointsTotal>=80 && (turnDone == false))
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

            if(minVal>= iterPair.second)
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
void FourthGame::testForWin()
{
    /*
    if(pointsTotal == 100)
    {

            for(int i = 0; i< sizeCallBack; i++)
                            this->cb[i](lastMe, lastOpponent, pointsTotal);


    }

    if(pointsTotal>100)
    {
            for(int i = 0; i< sizeCallBack; i++)
                            this->cb[i](lastMe, lastOpponent, pointsTotal);
    }*/

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









void FourthGame::start()
{

    sf::Music music;
    if (!music.openFromFile("sounds/2.ogg"))
    {
        return; // error
    }
    music.play();
    music.setLoop(true);

    this->deck = new Deck100();
    this->deck->putRandom();
    Card iterCard;
    pair<int,int> iterPair;
    deck0Sprite.scale(sf::Vector2f(1.2f, 1.2f));

    //void (*cb1)(bool lastMy, bool lastOpp, int pointsGame) = (FourthGame::this_is_callback_fn,this);
    //win_subscribe(cb1);

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

    Sprite restart;
    Texture trestart;
    trestart.loadFromFile("img/restart.png");
    restart.setTexture(trestart);
    restart.setPosition(765, 444);

    Sprite winn;
    Texture uWin;
    uWin.loadFromFile("img/uWin.jpg");
    winn.setTexture(uWin);
    winn.setPosition(595, 185);

    Sprite lose;
    Texture uLose;
    uLose.loadFromFile("img/uLose.jpg");
    lose.setTexture(uLose);
    lose.setPosition(595, 185);

    Sprite both;
    Texture theBoth;
    theBoth.loadFromFile("img/both.png");
    both.setTexture(theBoth);
    both.setPosition(600, 200);

    Sprite help;
    Texture helpt;
    helpt.loadFromFile("img/help4.png");
    help.setTexture(helpt);
    help.setPosition(0, 0);



    pointsTotalText.setCharacterSize(24);
    pointsTotalText.setPosition(20, 250);
    sf::Font font;
    font.loadFromFile("fonts/times.ttf");
    pointsTotalText.setFont(font);

    helpText.setCharacterSize(16);
    helpText.setPosition(750, 10);

    font.loadFromFile("fonts/times.ttf");
    helpText.setFont(font);
    helpText.setString("Press TAB to HELP");



    pair<int,int> selectPair;
    pair<int,int> endPair;
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


             if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if(inHelp == false){
                    if(gameEnded == false )
                    {
                        if((event.mouseButton.x > 100) && (event.mouseButton.x < (100 + (me.size()) * 18)) && (event.mouseButton.y > 370) && (event.mouseButton.y < 540))
                        {
                            selectPair = cardChoice(event.mouseButton.x, event.mouseButton.y);
                            pushSelectPair(selectPair);
                        }



                        // if ((event.mouseButton.x > 100) && ( event.mouseButton.x < 180) && (event.mouseButton.y > 100) && (event.mouseButton.y < 272))

                        //{


                        //}


                    }
                    if((event.mouseButton.x > 765) && (event.mouseButton.x < 900) && (event.mouseButton.y > 444) && (event.mouseButton.y < 533))
                    {
                        this->restart();
                    }
                    }
                }

}


            /**<<-------------------------------------------------------------->>**/
            /*
                        this->win->clear();
                        this->win->draw(background);
                        refreshText();



                        this->win->draw(restart);
                        for(int i = 0; i< me.size(); i++)
                        {
                            this->win->draw(spritesMe[i]);
                        }
                        for(int i = 0; i< opponent.size(); i++)
                        {
                            this->win->draw(spritesOpponent[i]);
                        }
                        if((this->winOpponent== true) && (this->winMe ==false ) )
                        {
                            this->gameEnded = true;
                            this->win->draw(lose);
                        }
                        if((this->winMe ==true )&& (this->winOpponent== false))
                        {
                            this->gameEnded = true;
                            this->win->draw(winn);
                        }
                        if(drawDeck0)
                            this->win->draw(deck0Sprite);
                        this->win->draw(pointsTotalText);

                        this->win->display();
                        if(mePush == true && gameEnded == false)
                        {
                            aiTurn();
                            Sleep(1500);

                            testForWin();
                            mePush = false;
                        }




            */

            /**<<-------------------------------------------------------------->>**/











            this->win->clear();
            this->win->draw(background);
            refreshText();



            this->win->draw(restart);
            for(int i = 0; i< me.size(); i++)
            {
                this->win->draw(spritesMe[i]);
            }
            for(int i = 0; i< opponent.size(); i++)
            {
                this->win->draw(spritesOpponent[i]);
            }
            if((this->winOpponent== true) && (this->winMe ==false ) )
            {
                this->gameEnded = true;
                this->win->draw(lose);
            }
            if((this->winMe ==true )&& (this->winOpponent== false))
            {
                this->gameEnded = true;
                this->win->draw(winn);
            }

            if(mePush == true && gameEnded == false)
            {
                aiTurn();
                //Sleep(1000);

                testForWin();
                mePush = false;
            }
            if(drawDeck0)
            this->win->draw(deck0Sprite);
            this->win->draw(pointsTotalText);
            if(inHelp== true)
            this->win->draw(help);
            this->win->draw(helpText);
            this->win->display();








        }
    }
}
void FourthGame::refreshText()
{
    std::stringstream ss;
    ss.clear();
    ss << pointsTotal;
    pointsTotalText.setString("In Deck: " + ss.str());

    ss.str("");


}
void FourthGame::restart()
{
    // deck = new Deck100();
    pointsTotal = 0;
    lastMe = false;
    lastOpponent = true;
    winMe = false;
    winOpponent = false;
    sizeCallBack = 0;
    this->deck->putRandom();
    Card iterCard;
    pair<int,int> iterPair;
    me.clear();
    opponent.clear();
    deck0.clear();
    //deck0Sprite.scale(sf::Vector2f(1.2f, 1.2f));

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
        //spritesMe[i].setPosition(100 + i *18, 370);
        //spritesMe[i].scale(sf::Vector2f(1.2f, 1.2f));
        me.pop_front();
        me.push_back(iterPair);
    }


    for(int i = 0; i< 24; i++)
    {
        iterPair = opponent.front();
        texturesOpponent[i].loadFromFile("img/finish_cards_sheet.png");

        spritesOpponent[i].setTexture(texturesOpponent[i]);
        spritesOpponent[i].setTextureRect(sf::IntRect((float)1027/13 * 0, (float)615/5 * 4, (float)1027/13, (float)615/5 ));
        //spritesOpponent[i].setPosition(100 + i *18, 10);
        //spritesOpponent[i].scale(sf::Vector2f(1.2f, 1.2f));
        opponent.pop_front();
        opponent.push_back(iterPair);
    }
    gameEnded = false;
    drawDeck0 = false;
    printf("\n<----------------RESTART------------------->\n");

}
void FourthGame::win_subscribe(CallbackFunction callback)
{
    cb[this->sizeCallBack] = callback;
    this->sizeCallBack++;
}
