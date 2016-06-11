#include "FifthGame.h"

int main()
{
    printf("!\n");

    RenderWindow win(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "9val");
    printf("!\n");
    FifthGame* game = new FifthGame(&win);
      printf("!\n");

    game->start();

    return 0;
}
