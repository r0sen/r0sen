#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <signal.h>

#include "21/FirstGame.h"
#include "seka/SecondGame.h"
#include "4ace/ThirdGame.h"
#include "100/FourthGame.h"
#include "9val/FifthGame.h"



#include "FirstGameBotton.h"
#include "SecondGameBotton.h"
#include "ThirdGameBotton.h"
#include "FourthGameBotton.h"
#include "FifthGameBotton.h"

using namespace sf;

/**-------------------------------------------------**/



int memento()
{
	int a=0;
	MessageBoxA(NULL,"POPADOS","POSIX Signal",NULL);
	return 0;
}
void posix_death_signal(int signum)
{
	memento();
	signal(signum, SIG_DFL);
	exit(3);
}



/**-------------------------------------------------------**/

int main()
{
    	signal(SIGSEGV, posix_death_signal);
    sf::RenderWindow window(sf::VideoMode(900, 533), "Card games", sf::Style::Close);

    FirstGameBotton * firstGameBotton = new FirstGameBotton();
    SecondGameBotton * secondGameBotton = new SecondGameBotton();
    ThirdGameBotton * thirdGameBotton = new ThirdGameBotton();
    FourthGameBotton * fourthGameBotton = new FourthGameBotton();
    FifthGameBotton * fifthGameBotton = new FifthGameBotton();


    Sprite background2;
    Texture backTexture;
    backTexture.loadFromFile("img/background2.jpg");
    background2.setTexture(backTexture);
    background2.setPosition(0, 0);




    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left))
            {

                if (firstGameBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                {
                    window.setVisible(0);
                    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "21 for fun!!!");

                    FirstGame * firstGame = new FirstGame(&win);
                    firstGame->start();
                    window.setVisible(1);
                }


                if (secondGameBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                {
                    window.setVisible(0);
                    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Seka");

                    SecondGame * secondGame = new SecondGame(&win);
                    secondGame->start();
                    window.setVisible(1);
                }

                if (thirdGameBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                {
                    window.setVisible(0);
                    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "4 Ace");

                    ThirdGame * thirdGame = new ThirdGame(&win);
                    thirdGame->start();
                    window.setVisible(1);
                }


                if (fourthGameBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                {
                    window.setVisible(0);
                    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "100");

                    FourthGame * fourthGame = new FourthGame(&win);
                    fourthGame->start();
                    window.setVisible(1);
                }

                /*if (fifthGameBotton->isPressed(event.mouseButton.x, event.mouseButton.y))
                {
                    window.setVisible(0);
                    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "9 Val");

                    FifthGame *fifthGame = new FifthGame(&win);
                    fifthGame->start();
                    window.setVisible(1);
                }*/
            }
        }
        window.clear();

        window.draw(background2);
        window.draw(firstGameBotton->sprite);
        window.draw(secondGameBotton->sprite);
        window.draw(thirdGameBotton->sprite);
        window.draw(fourthGameBotton->sprite);
       // window.draw(fifthGameBotton->sprite);

        window.display();
    }

    return 0;
}
