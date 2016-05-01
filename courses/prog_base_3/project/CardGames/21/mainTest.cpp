#include "card.h"
#include <iostream>


//bool isClicked
//void createCard
int main()
{
    //Sprite *card = new Sprite();
    //sf::Sprite *sprite = new sf::Sprite();

    RenderWindow win(VideoMode(1000, 600), "Spider");
    Card * hand1 = new Card();
    //hand1->sprite->
    Texture cardTexture;
    cardTexture.loadFromFile("cards/2_of_clubs.jpg");
    hand1->sprite.setTexture(cardTexture);
    hand1->sprite.setPosition(30,50);

    Sprite next;
    Texture nextText;
    nextText.loadFromFile("next.png");
    next.setTexture(nextText);
    next.setPosition(30,50);

    bool isMove = false;
    float dX = 0;
    float dY = 0;
    while (win.isOpen())
    {

        Vector2i pixelPos = Mouse::getPosition(win);
        Vector2f pos = win.mapPixelToCoords(pixelPos);
        Event event;
        while (win.pollEvent(event))
        {


            if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Left)
                    if (hand1->sprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        std::cout << "isClicked!\n";
                        dX = pos.x - hand1->sprite.getPosition().x;
                        dY = pos.y - hand1->sprite.getPosition().y;
                        isMove = true;
                    }


            if (event.type == Event::MouseButtonReleased)
                if (event.key.code == Mouse::Left) 
                    isMove = false;
            hand1->sprite.setColor(Color::White);
            if (event.type == Event::Closed)
            {
                win.close();
            }


        }
        if (isMove)  
        {
            hand1->sprite.setColor(Color::Green);
            hand1->sprite.setPosition(pos.x - dX, pos.y - dY);
        }
        win.clear();
        win.draw(next);
        win.draw(hand1->sprite);

        win.display();
    }

    return 0;
}
