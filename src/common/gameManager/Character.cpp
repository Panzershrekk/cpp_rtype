//
// Created by thomas on 15/01/18.
//

#include "Character.hpp"

Character::Character()
{
    this->_hp = 1;
}

Character::Character(const int &hp)
{
    this->_hp = hp;
}

Character::~Character() = default;

const int &Character::getHp() const
{
    return (this->_hp);
}

void Character::setHp(const int &hp)
{
    this->_hp = hp;
}