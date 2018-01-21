//
// Created by thomas on 17/01/18.
//


#include "Enemy.hpp"
#include "gameEngine/Image.hpp"
#include "gameEngine/Music.hpp"
#include "gameEngine/MusicManager.hpp"
#include "client/game/HeadUpDisplay.hpp"
#include "client/EventManager.hpp"
#include "game/EnemyRenderer.hpp"
#include "client/game/Starfield.hpp"
#include "game/GameRenderer.hpp"

GameRenderer::GameRenderer(Network::Core::UdpConnection &socket) :
        _player(), _clock(), _attackSpeed(), _socket(socket) {}

GameRenderer::~GameRenderer() = default;

void GameRenderer::startGame(Player &me, const Network::Core::Endpoint &serverEndpoint)
{
    int xSize = 1920;
    int ySize = 1080;
    Window window("RTYPE", 1920, 1080);

    /* STARFIELD */
    Image starsImage;
    Color c(0, 0, 0);
    starsImage.create(xSize, ySize, c.getColor().Black);
    Texture starsTexture;
    starsTexture.loadFromImage(starsImage.getImage());
    Sprite starsSprite;
    starsSprite.setTexture(starsTexture);
    Position2D p(0, 0);
    //starsSprite.setPosition(0,0);
    starsSprite.setPosition(p);
    Starfield backgroundStars(1920, 1080);
/* starfield */
    MusicManager m;
    //Music music("../resources/MainMenu.ogg", "MainMenu");
    m.AddNewMusic("../resources/MainMenu.ogg", "MainMenu");
    m.AddNewMusic("../resources/shootingstar.ogg", "ShootingStar");
    m.AddNewMusic("../resources/shrabelmatador.ogg", "Matador");
    m.getMusicByName("ShootingStar").playAudio();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();

                    break;
            }
        }
        if (this->_clock.getElapsedTime() > 1.0 / 60)
        {
            this->_player.update();
            this->_player.forbiddenMove(window);
            updateEntities();
            backgroundStars.updateStarfield();
            destroyEntities();
            this->_clock.restartTimer();
        }
        starsTexture.loadFromImage(starsImage.getImage());
        backgroundStars.drawStarfield(*starsTexture.getSfTexture());

        window.clear();
        window.draw(starsSprite);

        if (this->_attackSpeed.getElapsedTime() > 0.4)
        {
            bool    hasFire = false;

            if (sf::Joystick::isConnected(0))
            {
                if (sf::Joystick::isButtonPressed(0, 0))
                    hasFire = true;
            }
            else
            {
                if (Keyboard::isKeyPressed(Keyboard::Key::Space))
                    hasFire = true;
            }
            if (hasFire)
            {
                this->_player.fire();
                //EventManager::sendFire(this->_socket, me, serverEndpoint);
            }
            this->_attackSpeed.restartTimer();
        }
        window.draw(this->_player.getSprite());
        drawEntities(window);
        window.display();
    }
}

void GameRenderer::drawEntities(Window & window)
{
    /*for (auto &it : this->_player.getProjectileVector())
        window.draw(it->getSprite());
         */
    for (auto &it2 : this->_enemies)
        window.draw(it2->getSprite());

}

void GameRenderer::updateEntities()
{
   /* for (auto &it : this->_player.getProjectileVector())
        it->update(); */
    // TODO WTF
    for (auto &it2 : this->_enemies)
        it2->update();
}

void GameRenderer::destroyEntities()
{
    for (auto it = this->_enemies.begin(); it != this->_enemies.end(); ++it)
    {
        if (it->get()->getPosition().getX() < -100) {
            this->_enemies.erase(it);
            it--;
        }
    }
    for (auto it2 = this->_player.getProjectileVector().begin(); it2 != this->_player.getProjectileVector().end(); ++it2)
    {
        if (it2->get()->getPosition().getX() > 1900) {
            this->_player.getProjectileVector().erase(it2);
            it2--;
        }
    }
}

void    GameRenderer::addEnemies(Enemy &newEnemy)
{
    for (const auto enemy : this->_enemies)
    {
        if (enemy->getId() == newEnemy.getId())
            return;
    }
    auto    newRenderEnemy = std::make_shared<EnemyRenderer>(newEnemy.getId());
    newRenderEnemy->setPosition(newEnemy.getPosition());
    this->_enemies.emplace_back(newRenderEnemy);
}