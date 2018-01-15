//
// Created by thomas on 11/01/18.
//

#include "TimeManager.hpp"

TimeManager::TimeManager() : _clock() , _time()
{
}

TimeManager::~TimeManager()
{
}

float TimeManager::getElapsedTime() const
{
  return (_clock.getElapsedTime().asSeconds());
}

float TimeManager::getDeltaTime()
{
  return (restartTimer().asSeconds());
}

sf::Time TimeManager::restartTimer()
{
  return (_clock.restart());
}