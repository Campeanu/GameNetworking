#include <client/Game.h>

namespace game_networking {

    const sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);

    Game::Game()
    {
        this->positionTimer = sf::Time::Zero;
        this->port = 45000;
        this->ipAdress = "localhost";

        this->network = std::make_unique<Network>(ipAdress, port);

        this->pSprite.setName("Valko");

        this->mWindow.create(sf::VideoMode(840, 680), "Game");
        this->socket.setBlocking(false);
        this->mWindow.setFramerateLimit(60);

        this->dir[0] = 0;
        this->dir[1] = 0;
        this->dir[2] = 0;
        this->dir[3] = 0;

        srand(time(0));
    }

    Game::~Game()
    {
        this->network->disconnect(&this->pSprite);
    }

    void Game::procesEvents()
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    mWindow.close();
                    break;
                }
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                }
                break;

            }
        }

        if (mWindow.hasFocus())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !movingDiagonal)
            {
                pSprite.move(0, -2);
                pSprite.setDirection(sf::Vector2f(0, -2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !movingDiagonal)
            {
                pSprite.move(-2, 0);
                pSprite.setDirection(sf::Vector2f(-2, 0));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !movingDiagonal)
            {
                pSprite.move(0, 2);
                pSprite.setDirection(sf::Vector2f(0, 2));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !movingDiagonal)
            {
                pSprite.move(2, 0);
                pSprite.setDirection(sf::Vector2f(2, 0));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                movingDiagonal = true;
                pSprite.move(1.4, -1.4);
                pSprite.setDirection(sf::Vector2f(1.4, -1.4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                movingDiagonal = true;
                pSprite.move(-1.4, -1.4);
                pSprite.setDirection(sf::Vector2f(-1.4, -1.4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                movingDiagonal = true;
                pSprite.move(1.4, 1.4);
                pSprite.setDirection(sf::Vector2f(1.4, 1.4));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                movingDiagonal = true;
                pSprite.move(-1.4, 1.4);
                pSprite.setDirection(sf::Vector2f(-1.4, 1.4));
            }
            else
                movingDiagonal = false;

            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                pSprite.setDirection(sf::Vector2f(0, 0));
        }
    }


    void Game::update()
    {
        if (lastDirectionSent != pSprite.getDirection())
        {
            network->send(&pSprite);
            lastDirectionSent = pSprite.getDirection();
        }

        positionTimer += clock.restart();
        if (positionTimer >= sf::seconds(1))
        {
            network->sendPosition(&pSprite);
            positionTimer = sf::Time::Zero;
        }

        network->receive(enemies, &pSprite);

        for (unsigned int i = 0; i < enemies.size(); i++)
        {
            enemies[i]->move(enemies[i]->getDirection());
        }
    }

    void Game::render()
    {
        mWindow.clear(sf::Color::Cyan);
        for (unsigned int i = 0; i < enemies.size(); i++)
            mWindow.draw(*enemies[i]);
        mWindow.draw(pSprite);
        mWindow.display();
    }

    void Game::run()
    {
        while (mWindow.isOpen())
        {
            procesEvents();
            update();
            render();
        }
    }

} // namespace: game_networking
