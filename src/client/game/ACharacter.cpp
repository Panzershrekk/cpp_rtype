//
// Created by thomas on 15/01/18.
//

#include <ACharacter.hpp>

ACharacter::ACharacter()
{
  this->_hp = 1;
}

ACharacter::ACharacter(int hp)
{
  this->_hp = hp;
}

int ACharacter::getHp() const
{
  return (this->_hp);
}

void ACharacter::setHp(int hp)
{
  this->_hp = hp;
}