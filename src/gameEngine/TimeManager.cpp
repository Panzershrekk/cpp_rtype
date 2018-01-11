//
// Created by thomas on 11/01/18.
//

#include "TimeManager.hpp"

TimeManager::TimeManager() : _clock()
{
}

TimeManager::~TimeManager()
{
}

sf::Time TimeManager::getElapsedTime() const
{
  return (this->_clock.getElapsedTime());
}

/*sf::Time TimeManager::restart() const
{
  return (this->_clock.restart());
}*/