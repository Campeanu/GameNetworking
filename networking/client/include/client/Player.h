#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include <SFML/Graphics.hpp>

namespace game_networking {

    class Player
        : public sf::Sprite
    {
    public:
        Player();
        virtual ~Player() = default;

        void setID(int id);
        int getID();

        void setName(std::string name);
        std::string getName();

        void setHealth(float health);
        float getHealth();

        void setAttackDamage(int atackDamage);
        float getAttackDamage();

        void setDirection(sf::Vector2f direction);
        sf::Vector2f getDirection();

        bool isReady();

    private:
        // Player sprite and texture
        sf::Texture playerTexture;

        // Player id
        int id;

        std::string name;

        bool m_isReady;

        float health;
        float attackDamage;

        sf::Vector2f direction;
    };

} // namespace: game_networking

#endif // PLAYER_H
