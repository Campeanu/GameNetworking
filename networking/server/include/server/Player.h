#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <memory>
#include <string>

namespace game_networking {

    class Player
    {
    public:
        Player(std::unique_ptr<sf::TcpSocket>* socket, sf::Vector2f position, int id);

        sf::TcpSocket* getSocket();

        int getId();

        void setName(const std::string name);
        std::string getName();

        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);
        sf::Vector2f getPosition();

        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float x, float y);
        sf::Vector2f getVelocity();

        void setTimeout(sf::Time time);
        sf::Time getTimeout();

        void update(float deltaTime);
    private:
        std::unique_ptr<sf::TcpSocket> m_socket = nullptr;

        int m_id;
        std::string m_name;

        sf::Vector2f m_position;
        sf::Vector2f m_velocity;

        sf::Time m_timeout;
    };

} // namespace: game_networking

#endif // PLAYER_H
