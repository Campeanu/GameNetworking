#include "server/Server.h"

int main()
{
    game_networking::Server* server = new game_networking::Server();
    server->run();
    delete server;
    return 0;
}
