#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <memory>

#include <SFML/Network.hpp>

#include "Player.h"
#include "Enemy.h"

namespace game_networking {

    class Network {
    public:
        /**
         * NOTE: sf::IpAddress: Encapsulate an IPv4 network address. Is a utility class for
         * manipulating network addresses. It provides a set a implicit constructors and conversion
         * functions to easily build or transform an IP address from/to various representations.
         */
        Network(sf::IpAddress& ip, unsigned short& port);

        /**
         * NOTE: Default constructor, no need for an implementation.
         */
        virtual ~Network() = default;

        /**
         * NOTE: Use to diconnect player from the server.
         * @param player
         */
        void disconnect(Player* player);

        /**
         * NOTE: This function use is to send data the player ip and direction to server.
         * @param player
         */
        void send(Player* player);

        /**
         * NOTE: This function use is to send the player name to server.
         * @param player
         */
        void sendMyName(Player* player);

        /**
         * NOTE: This function use is to send a message to server.
         * @param player
         * @param message
         */
        void sendMessage(Player* player, std::string& message);

        /**
         * NOTE: This function use is to send the player position to server.
         * @param player
         */
        void sendPosition(Player* player);

        /**
         * NOTE: This function use is to get acces to private member textMessage.
         * @return the value textMessage
         */
        std::string getMessage();

        /**
         * NOTE: This function use is to get a list of the player that are connected to the server.
         * @param player
         */
        void getPlayerList(Player* player);

        /**
         * NOTE: This function use is to get a list of the player that are connected to the server.
         * @param enemies
         * @param player
         */
        void receive(std::vector<std::unique_ptr<Enemy>>& enemies, Player* player);
    private:
        /**
         * NOTE: sf::TcpSocket: Specialized socket using the TCP protocol. TCP is a connected
         * protocol, which means that a TCP socket can only communicate with the host it is
         * connected to. It can't send or receive anything if it is not connected. The TCP
         * protocol is reliable but adds a slight overhead.
         */
        sf::TcpSocket connection;

        // connect = true if the client is connected or false if client is not connected
        bool connected;
        int packetCounter = 0;

        /**
         * NOTE: sf::Clock: Utility class that measures the elapsed time. Is a lightweight
         * class for measuring time. Its provides the most precise time that the underlying
         * OS can achieve.
         */
        sf::Clock packetClock;

        std::string textMessage;
    };

} // namespace: game_networking

#endif // NETWORK_H
