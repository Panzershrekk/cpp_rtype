//
// Created by thomas on 15/01/18.
//

#include "Enemy.hpp"

Enemy::Enemy() : Character(1)
{
  this->_physic.setSpeed(2);
  randomizePosition();
}

Enemy::~Enemy()
{
}

void Enemy::randomizePosition()
{
  std::srand(std::time(nullptr));
  int randNum = std::rand()%(500-1 + 1) + 1;
  Position2D p(800, randNum);
  setPosition(p);
}

AIManager Enemy::getAI() const
{
  return (this->_ai);
}
