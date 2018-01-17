//
// Created by thomas on 16/01/18.
//

#include "AEntity.hpp"

AEntity::AEntity()
{
  static int id = 0;
  this->_id = id;
  id++;
}

void AEntity::setPosition(Position2D &pos)
{
  this->_pos = pos;
}

Position2D AEntity::getPosition() const
{
  return this->_pos;
}

int AEntity::getId() const
{
  return this->_id;
}