#include "FifthGame.h"
#include <sstream>
#include <iostream>
#include <windows.h>
#include <SFML/Audio.hpp>
//bool counter;
FifthGame::FifthGame(RenderWindow* winInput)
{
    this->win = winInput;
    deck = new DeckFifth();
    deck2 = new DeckFifth();
    gameLose = false;
    gameWin = false;

    bankTotal = 200;
    bit = 0;
    inHelp = false;

}

void FifthGame::winLook()
{
    int sett;
    for(int i = 0; i<9; i++)
    {
        if( ( table[i].getColorIdentifier() ==   myCard.getColorIdentifier()) && ( table[i].getValueIdentifier() ==   myCard.getValueIdentifier()))
        {
            sett=i;
            break;
        }
    }
    if((sett == 0) || (sett == 1))
    {
        bankTotal+=bit;
        bit=0;
    }
    if((sett == 2) || (sett == 3))
    {
        bankTotal+=(bit*2);
        bit=0;
    }

    if((sett == 4) || (sett == 5))
    {
        bankTotal+=(bit*4);
        bit=0;
    }
    if((sett == 6) || (sett == 7))
    {
        bankTotal+=(bit*8);
        bit=0;
    }
    if((sett == 8))
    {
        bankTotal+=(bit*9);
        bit=0;
    }


    else
    {
        bit = 0;
    }
}




void FifthGame::reveal()
{

    for(int i = 0; i<9; i++)
    {
        table[i].setTexture();
    }
    winLook();

    roundEnded = true;




}



void FifthGame::bitSet()
{
    bit+=5;
    bankTotal-=5;
    if(bankTotal == 0)
        reveal();
    if(bankTotal < 0)
    {
        bankTotal +=5;
        bit-=5;
        reveal();
    }
    if(bankTotal == 0)
        gameLose = true;

    if(bankTotal >=5000)
        gameWin = true;
}


void FifthGame::nextRound2()
{

    this->deck->putRandom();
    this->deck2->putRandom();
    this->deck2->putRandom();
    this->deck2->putRandom();
    myCard = deck2->getCard();


    for(int i = 0; i<9; i++)
    {
        table[i] = deck->getCard();
        table[i].texture.loadFromFile("img/finish_cards_sheet.png");

        table[i].sprite.setTexture(table[i].texture);
        //table[i].setTexture();
        table[i].sprite.setTextureRect(sf::IntRect((float)1027/13 * 0, (float)615/5 * 4, (float)1027/13, (float)615/5 ));
        table[i].sprite.scale(sf::Vector2f(0.85f, 0.85f));
        myCard.setTexture();
    }
    roundEnded = false;



        table[0].sprite.setPosition(10, 2);
    table[1].sprite.setPosition(80, 2);
    table[2].sprite.setPosition(10, 108);
    table[3].sprite.setPosition(80, 108);
    table[4].sprite.setPosition(10, 214);
    table[5].sprite.setPosition(80, 214);
    table[6].sprite.setPosition(10, 320);
    table[7].sprite.setPosition(80, 320);
    table[8].sprite.setPosition(10, 426);
    myCard.setTexture();
    myCard.sprite.setPosition(400,200);
}


void FifthGame::start()
{
       /* sf::Music music;
    if (!music.openFromFile("sounds/8.ogg"))
    {
        return; // error
    }*/
printf("9VAL\n");
    //this->deck = new DeckFifth();
   // this->deck->putRandom();
    this->deck2 = new DeckFifth();
    //this->deck2 = new DeckFifth();
    //this->deck2->putRandom();
    //this->deck2->putRandom();
    this->deck2->putRandom();

//   CardVal myCard = new CardVal();
    //CardVal myCard = new CardVal();
    //myCard = deck2->getCard();

    myCard = deck->getCard();
        myCard.setTexture();

    myCard.sprite.setPosition(400,200);





    for(int i = 0; i<9; i++)
    {
        table[i] = deck->getCard();
        table[i].texture.loadFromFile("img/finish_cards_sheet.png");

        table[i].sprite.setTexture(table[i].texture);
        //table[i].setTexture();
        table[i].sprite.setTextureRect(sf::IntRect((float)1027/13 * 0, (float)615/5 * 4, (float)1027/13, (float)615/5 ));
        table[i].sprite.scale(sf::Vector2f(0.85f, 0.85f));

    }

    table[0].sprite.setPosition(10, 2);

    table[1].sprite.setPosition(80, 2);

    table[2].sprite.setPosition(10, 108);

    table[3].sprite.setPosition(80, 108);
    table[4].sprite.setPosition(10, 214);
    table[5].sprite.setPosition(80, 214);
    table[6].sprite.setPosition(10, 320);

    table[7].sprite.setPosition(80, 320);

    table[8].sprite.setPosition(10, 426);
printf("9VAL\n");



    Sprite background;
    Texture backTexture;
    backTexture.loadFromFile("img/wood-texture.jpg");
    background.setTexture(backTexture);
    background.setPosition(0, 0);



//U WIN U LOSE PICS

    Sprite restart;
    Texture trestart;
    trestart.loadFromFile("img/restart.png");
    restart.setTexture(trestart);
    restart.setPosition(765, 444);

    Sprite winn;
    Texture uWin;
    uWin.loadFromFile("img/win2.png");
    winn.setTexture(uWin);
    winn.setPosition(0, 0);

    Sprite lose;
    Texture uLose;
    uLose.loadFromFile("img/lose2.png");
    lose.setTexture(uLose);
    lose.setPosition(0, 0);

    Sprite both;
    Texture theBoth;
    theBoth.loadFromFile("img/both.png");
    both.setTexture(theBoth);
    both.setPosition(600, 200);

    Sprite t5;
    Texture t5t;
    t5t.loadFromFile("img/5.png");
    t5.setTexture(t5t);
    t5.setPosition(465, 444);

    Sprite seta;
    Texture setat;
    setat.loadFromFile("img/set.png");
    seta.setTexture(setat);
    seta.setPosition(565, 444);


    Sprite nexta;
    Texture nextat;
    nextat.loadFromFile("img/next2.png");
    nexta.setTexture(nextat);
    nexta.setPosition(665, 444);

    Sprite help;
    Texture helpt;
    helpt.loadFromFile("img/help5.png");
    help.setTexture(helpt);
    help.setPosition(0, 0);




    bankTotalText.setCharacterSize(24);
    bankTotalText.setPosition(400, 400);
    sf::Font font;
    font.loadFromFile("fonts/times.ttf");
    bankTotalText.setFont(font);
    helpText.setCharacterSize(16);
    helpText.setPosition(750, 10);

    font.loadFromFile("fonts/times.ttf");
    helpText.setFont(font);
    helpText.setString("Press TAB to HELP");
printf("9VAL\n");


    bitText.setCharacterSize(24);
    bitText.setPosition(400, 350);


    bitText.setFont(font);


printf("9VAL\n");

    while (this->win->isOpen())
    {printf("9VAL\n");

    printf("9VAL\n");

     Event event;
        printf("9VAL\n");

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
                    if(!gameWin && !gameLose){
                    if(roundEnded == false)
                    {
                        if((event.mouseButton.x > 465) && (event.mouseButton.x < 555) && (event.mouseButton.y > 444) && (event.mouseButton.y < 514))
                        {
                            bitSet();
                        }
                        if((bit != 0)&&(event.mouseButton.x > 565) && (event.mouseButton.x < 655) && (event.mouseButton.y > 444) && (event.mouseButton.y < 514))
                        {
                            reveal();
                        }



                    }
                    if(roundEnded == true)
                    {
                        if((event.mouseButton.x > 665) && (event.mouseButton.x < 755) && (event.mouseButton.y > 444) && (event.mouseButton.y < 514))
                        {
                            nextRound2();
                        }

                    }
                }
                    if((event.mouseButton.x > 765) && (event.mouseButton.x < 900) && (event.mouseButton.y > 444) && (event.mouseButton.y < 533))
                    {
                        this->restart();
                    }
                }
            }}

            this->win->clear();
            this->win->draw(background);


            this->win->draw(myCard.sprite);


            if(!roundEnded)
            {
                this->win->draw(t5);
                if((bit != 0))
                this->win->draw(seta);
            }

            if(roundEnded)
                this->win->draw(nexta);

            this->win->draw(bankTotalText);
            if(!roundEnded)
            this->win->draw(bitText);
            for(int i = 0; i < 9; i++)
            {
                this->win->draw(table[i].sprite);
            }



            if(gameLose)
                this->win->draw(lose);


            if(gameWin)
                this->win->draw(winn);


            refreshText();

                        this->win->draw(restart);





      if(inHelp== true)
            this->win->draw(help);
            this->win->draw(helpText);

            this->win->display();

        }


    }

}

void FifthGame::refreshText()
{
    std::stringstream ss;
    ss.clear();
    ss << bankTotal;
    bankTotalText.setString("You Bank: " + ss.str());

    ss.str("");

    ss.clear();
    ss << bit;
    bitText.setString("    You Bit: " + ss.str());



}
void FifthGame::restart()
{
    bankTotal = 200;
    bit = 0;
    gameLose = false;
    gameWin = false;
    roundEnded = false;
    this->deck->putRandom();
    this->deck2->putRandom();
    this->deck2->putRandom();
    this->deck2->putRandom();
    myCard = deck2->getCard();


    for(int i = 0; i<9; i++)
    {
        table[i] = deck->getCard();
        table[i].texture.loadFromFile("img/finish_cards_sheet.png");

        table[i].sprite.setTexture(table[i].texture);
        //table[i].setTexture();
        table[i].sprite.setTextureRect(sf::IntRect((float)1027/13 * 0, (float)615/5 * 4, (float)1027/13, (float)615/5 ));
        table[i].sprite.scale(sf::Vector2f(0.85f, 0.85f));
        myCard.setTexture();
    }
    roundEnded = false;



    table[0].sprite.setPosition(10, 2);
    table[1].sprite.setPosition(80, 2);
    table[2].sprite.setPosition(10, 108);
    table[3].sprite.setPosition(80, 108);
    table[4].sprite.setPosition(10, 214);
    table[5].sprite.setPosition(80, 214);
    table[6].sprite.setPosition(10, 320);
    table[7].sprite.setPosition(80, 320);
    table[8].sprite.setPosition(10, 426);
    myCard.setTexture();
    myCard.sprite.setPosition(400,200);

}
