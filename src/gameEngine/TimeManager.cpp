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

void TimeManager::restartTimer()
{
  _clock.restart();
}