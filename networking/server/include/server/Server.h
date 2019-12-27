#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <SFML/Network.hpp>
#include <memory>
#include <vector>
#include <string>
#include "Player.h"

namespace game_networking {

    class Server
    {
    public:
        Server();
        void run();

    private:

        void sendPacket(sf::Packet& packet, unsigned int skip = -1);
        bool m_isRunning;

        sf::IpAddress m_ipAdress;
        unsigned short m_port;

        sf::TcpListener m_listener;
        sf::SocketSelector m_selector;

        int m_maxPlayerNumber;
        int m_currentID;
        int m_playerNumber;

        std::vector<Player> m_playerList;
        char m_tmp[1400];

        sf::Clock m_clock;


    };

} // namespace: game_networking

#endif // SERVER_H
