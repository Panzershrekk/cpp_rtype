//
// Created by thomas on 15/01/18.
//

#include "server/GameManager/Character.hpp"

Character::Character()
{
  this->_hp = 1;
}

Character::Character(int hp)
{
  this->_hp = hp;
}

int Character::getHp() const
{
  return (this->_hp);
}

void Character::setHp(int hp)
{
  this->_hp = hp;
}