//
// Created by thomas on 15/01/18.
//

#include "Player.hpp"

Player::Player() : Character(100)
{
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

const std::string   &Player::getName() const
{
    return this->_name;
}

const Network::Core::Endpoint& Player::getEndpoint() const
{
    return this->_endpoint;
}