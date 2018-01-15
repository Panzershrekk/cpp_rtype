//
// Created by thomas on 15/01/18.
//

#include "Player.hpp"

Player::Player() : ACharacter(100)
{
  this->_score = 0;
}

Player::~Player()
{
}

void Player::setScore(int score)
{
  this->_score = score;
}

int Player::getScore() const
{
  return (this->_score);
}

void Player::addScore(int score)
{
  this->_score += score;
}
