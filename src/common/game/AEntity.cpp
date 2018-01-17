//
// Created by thomas on 16/01/18.
//

#include "AEntity.hpp"

AEntity::AEntity()
{

}

void AEntity::setPosition(Position2D &pos)
{
  this->_pos = pos;
}

Position2D AEntity::getPosition() const
{
  return this->_pos;
}
