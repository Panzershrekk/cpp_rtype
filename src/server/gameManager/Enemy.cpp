//
// Created by thomas on 15/01/18.
//

#include <Sprite.hpp>
#include "Enemy.hpp"

Enemy::Enemy() : Character(1)
{
  this->_physic.setSpeed(3);
  this->_hitboxSize = Position2D(25, 24);
  this->_rect = Rectangle(this->_pos.getX() - this->_hitboxSize.getX(), this->_pos.getY() - this->_hitboxSize.getY(), 14, 12);
  randomizePosition();
}

Enemy::~Enemy()
{
}

void Enemy::randomizePosition()
{
  std::srand(std::time(nullptr));
  int randNum = std::rand()%(500-1 + 1) + 1;
  Position2D p(1800, randNum);
  setPosition(p);
}

AIManager Enemy::getAI() const
{
  return (this->_ai);
}

void Enemy::update()
{
  this->_ai.PredefinedRightToLeftSinus(this->_pos, this->_physic.getSpeed());
  this->_rect.changeTopLeft(this->_hitboxSize);
}
