#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include <SFML/Graphics.hpp>

namespace game_networking {

    class Enemy
        : public sf::Sprite
    {
    public:
        Enemy(int id, sf::Vector2f position, std::string name);
        virtual ~Enemy() = default;

        void setID(int id);
        int getID();

        void setName(std::string name);
        std::string getName();

        void setHealth(float health);
        float getHealth();

        void setDirection(sf::Vector2f direction);
        sf::Vector2f getDirection();

    private:
        sf::Texture playerTexture;

        int id;

        std::string name;

        float health;

        sf::Vector2f direction;
    };

} // namespace: game_networking

#endif // ENEMY_H
