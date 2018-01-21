//
// Created by thomas on 15/01/18.
//

#include <server/EventManager.hpp>
#include "TimeManager.hpp"
#include "GameManager.hpp"

GameManager::GameManager(Network::Core::UdpConnection &socket) : _socket(socket)
{
}

GameManager::~GameManager() = default;

std::vector<Player>& GameManager::getPlayers() { return this->_player; }
const std::vector<Enemy>& GameManager::getEnemies() const { return this->_ennemy; }

/**
 *
 */
void GameManager::update()
{
    TimeManager clock;
    TimeManager spwanRate;
    Network::Core::Endpoint     ep("127.0.0.1", 4242);

    while (playerStillAlive()) //Todo Connexion rompu? Personnage tous mort ?
    {
        if (clock.getElapsedTime() > 1.0 / 60)
        {
            // Todo Send les pos de tout les trucs

            /*
             * if player fire
             * createProjectile(Player that fired)
             * */
            EventManager::RefreshEnemies(this->_socket, *this);

            dumpEnemy();
            missileCollide();
            updateEntities();
            removeEntities();
            clock.restartTimer();
        }
        if (spwanRate.getElapsedTime() > 1.0)
        {
            spawnEnnemy();
            spwanRate.restartTimer();
        }
    }

}

void GameManager::createProjectile(Player &player)
{
    this->_projetcile.emplace_back(Projectile(player.getPosition()));
}

void GameManager::spawnEnnemy()
{
    this->_ennemy.emplace_back(Enemy());
}

void GameManager::addPlayer(Player player)
{
    this->_player.push_back(player);
}

bool GameManager::playerStillAlive()
{
    for (auto it : this->_player)
    {
        if (it.getHp() > 0)
            return (true);
    }
    return (false);
}


void GameManager::updateEntities()
{
    for (auto &it : this->_ennemy)
        it.update();
    for (auto &it2 : this->_projetcile)
        it2.update();
}


void GameManager::removeEntities()
{
    for (auto it = this->_ennemy.begin(); it != this->_ennemy.end(); ++it) {
        if (it->getPosition().getX() < -100) {
            it = this->_ennemy.erase(it);
            it--;
        }
    }

    for (auto it = this->_projetcile.begin(); it != this->_projetcile.end(); ++it) {
        if (it->getPosition().getX() > 1700) {
            it = this->_projetcile.erase(it);
            it--;
        }
    }
}

void GameManager::dumpPlayer()
{
    for (auto it : this->_player)
    {
        std::cout << it.getId() << " " << it.getName() << " " << it.getPosition().getX() << " "<< it.getPosition().getY() << std::endl;
    }
}

void GameManager::dumpEnemy()
{
    std::cout << "-------------------------" << std::endl;
    for (auto &it : this->_ennemy)
    {
        std::cout << "This is an ennemy with id " << it.getId() << " " << it.getPosition().getX() << " "<< it.getPosition().getY() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

bool GameManager::missileCollide()
{
    /*for (auto it : this->_projetcile)
    {
      for (auto it2 : this->_ennemy)
      {
      if (it.getRectangle().intersects(it2.getRectangle())) {
        std::cout << it.getId() << std::endl;
        std::cout << it2.getId() << std::endl;
        return (true);
      }
      }
    }*/
    return false;
}
