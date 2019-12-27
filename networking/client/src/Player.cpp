#include <client/Player.h>

namespace game_networking {

    Player::Player()
        : health {100},
          id {-1}
    {
        if(!this->playerTexture.loadFromFile("D:/etc/GameNetworking/tmp/resources/player/player.png"))
            std::cout << "Error loading player.png" << std::endl;
        this->setTexture(this->playerTexture);
    }

    void Player::setID(int id)
    {
        this->id = id;
    }

    int Player::getID()
    {
        return this->id;
    }

    void Player::setName(std::string name)
    {
        this->name = name;
    }

    std::string Player::getName()
    {
        return this->name;
    }

    void Player::setHealth(float health)
    {
        this->health = health;
    }

    float Player::getHealth()
    {
        return this->health;
    }

    void Player::setAttackDamage(int atackDamage)
    {
        this->attackDamage = attackDamage;
    }

    float Player::getAttackDamage()
    {
        return this->attackDamage;
    }

    void Player::setDirection(sf::Vector2f direction)
    {
        this->direction = direction;
    }

    sf::Vector2f Player::getDirection()
    {
        return this->direction;
    }

    bool Player::isReady()
    {
        return this->m_isReady;
    }

} // namespace: game_networking
