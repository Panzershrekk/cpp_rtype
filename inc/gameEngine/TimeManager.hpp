//
// Created by thomas on 11/01/18.
//

#ifndef CPP_RTYPE_TIMEMANAGER_HPP
#define CPP_RTYPE_TIMEMANAGER_HPP

#include "SFML/System/Clock.hpp"
#include "Time.hpp"

class TimeManager
{
  public:
    TimeManager();
    ~TimeManager();

    sf::Time getElapsedTime() const;
    //sf::Time restart() const;

  private:
    sf::Clock _clock;
};

#endif //CPP_RTYPE_TIMEMANAGER_HPP
