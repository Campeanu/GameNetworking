#ifndef GAME_H
#define GAME_H

#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Network.h"

namespace game_networking {

    class Game {
    public:
        Game();
        virtual ~Game();

        void procesEvents();
        void update();
        void render();

        void run();
    private:
        static const sf::Time timePerFrame;

        sf::RenderWindow mWindow;

        sf::TcpSocket socket;

        unsigned short port;
        sf::IpAddress ipAdress;

        sf::Clock clock;

        std::vector<sf::Sprite> remotePlayers;

        Player pSprite;
        std::vector<std::unique_ptr<Enemy>> enemies;
        std::unique_ptr<Network> network;

        bool dir[4];
        sf::Vector2f lastDirectionSent;
        bool movingDiagonal;

        sf::Time positionTimer;
    };


} // namespace: game_networking

#endif // GAME_H
