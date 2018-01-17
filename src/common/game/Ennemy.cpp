//
// Created by thomas on 15/01/18.
//

#include "Ennemy.hpp"

Ennemy::Ennemy() : Character(1)
{
  this->_physic.setSpeed(2);
  randomizePosition();
}

Ennemy::~Ennemy()
{
}

void Ennemy::randomizePosition()
{
  std::srand(std::time(nullptr));
  int randNum = std::rand()%(500-1 + 1) + 1;
  Position2D p(800, randNum);
  setPosition(p);
}

AIManager Ennemy::getAI() const
{
  return (this->_ai);
}
