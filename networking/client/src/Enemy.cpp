#include <client/Enemy.h>

namespace game_networking {

    Enemy::Enemy(int id, sf::Vector2f position, std::string name)
        : health(100),
          id(id),
          name("default")
    {
        if (!this->playerTexture.loadFromFile("D:/etc/GameNetworking/tmp/resources/player/player.png"))
            std::cout << "Error loading player.png" << std::endl;

        this->setTexture(playerTexture);
        this->setPosition(position);
        this->setName(name);
    }

	void Enemy::setID(int id)
    {
        this->id = id;
    }

    int Enemy::getID()
    {
        return this->id;
    }

    void Enemy::setName(std::string name)
    {
        this->name = name;
    }

    std::string Enemy::getName()
    {
        return this->name;
    }

	void Enemy::setHealth(float health)
    {
        this->health = health;
    }

    float Enemy::getHealth()
    {
        return this->health;
    }

	void Enemy::setDirection(sf::Vector2f direction)
    {
        this->direction = direction;
    }

	sf::Vector2f Enemy::getDirection()
    {
        return this->direction;
    }

} // namespace: game_networking
