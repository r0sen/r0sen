#include "Game.h"

int main()
{
    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Poker Courses");

    Game* game = new Game(&win);
    game->start();

    return 0;
}
