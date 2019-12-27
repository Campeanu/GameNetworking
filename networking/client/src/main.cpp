#include <client/Game.h>

int main()
{
    game_networking::Game* game = new game_networking::Game();
    game->run();
    delete game;
    return 0;
}
