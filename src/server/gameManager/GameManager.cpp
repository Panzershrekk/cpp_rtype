//
// Created by thomas on 15/01/18.
//

#include "GameManager.hpp"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}


void GameManager::update()
{
}

void GameManager::createProjectile()
{
}

void GameManager::spawnEnnemy()
{
  Enemy e;
  this->_ennemy.push_back(e);
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