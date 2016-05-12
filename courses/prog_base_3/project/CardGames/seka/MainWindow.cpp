#include "Game.h"

int main()
{
    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Seka Leaff");

    Game* game = new Game(&win);
    game->start();

    return 0;
}
