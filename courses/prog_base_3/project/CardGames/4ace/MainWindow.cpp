#include "Game.h"

int main()
{
    printf("!\n");

    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "4ace");
    printf("!\n");
    Game* game = new Game(&win);
      printf("!\n");

    game->start();

    return 0;
}
