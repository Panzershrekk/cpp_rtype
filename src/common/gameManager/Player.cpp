//
// Created by thomas on 15/01/18.
//

#include "Player.hpp"

Player::Player() : Character(100)
{
  this->_hitboxSize = Position2D(33, 15);
  this->_rect = Rectangle(this->_pos.getX() - this->_hitboxSize.getX(), this->_pos.getY() - this->_hitboxSize.getY(), 14, 12);

  this->_physic.setSpeed(2);
  this->_score = 0;
  this->_name = "Unknown";
}

Player::Player(const std::string & name) : Character(100)
{
  this->_physic.setSpeed(2);
  this->_score = 0;
  this->_name = name;
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

void Player::setName(const std::string &name)
{
  this->_name = name;
}

std::string Player::getName() const
{
  return this->_name;
}

void Player::update()
{
  Position2D p(Position2D(this->_pos.getX() - this->_hitboxSize.getX(), this->_pos.getY() - this->_hitboxSize.getY()));
  this->_rect.changeTopLeft(p);
}
