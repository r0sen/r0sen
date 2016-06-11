#include "Game.h"

int main()
{
    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "21 for fun!!!");

    Game* game = new Game(&win);
    game->start();

    return 0;
}
