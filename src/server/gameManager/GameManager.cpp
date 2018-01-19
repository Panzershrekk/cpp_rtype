//
// Created by thomas on 15/01/18.
//

#include "TimeManager.hpp"
#include "GameManager.hpp"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}


void GameManager::update()
{
  TimeManager clock;

  while (true) //Todo Connexion rompu? Personnage tous mort ?
  {
    if (clock.getElapsedTime() > 1.0 / 60)
    {
      // Todo Send les pos de tout les trucs
    }
  }

}

void GameManager::createProjectile(Player &player)
{
  this->_projetcile.emplace_back(Projectile());
}

void GameManager::spawnEnnemy()
{
  this->_ennemy.emplace_back(Enemy());
}

void GameManager::addPlayer(Player &player)
{
  this->_player.push_back(player);
}

void GameManager::dumpPlayer()
{
  for (auto it : this->_player)
  {
    std::cout << it.getId() << " " << it.getName() << " " << it.getPosition().getX() << " "<< it.getPosition().getY() << std::endl;
  }
}

void GameManager::dumpEnnemy()
{
  for (auto it : this->_ennemy)
  {
    std::cout << "This is an ennemy with id " << it.getId() << " " << it.getPosition().getX() << " "<< it.getPosition().getY() << std::endl;
  }
}