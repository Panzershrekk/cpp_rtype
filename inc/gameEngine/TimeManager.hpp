//
// Created by thomas on 11/01/18.
//

#ifndef CPP_RTYPE_TIMEMANAGER_HPP
#define CPP_RTYPE_TIMEMANAGER_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class TimeManager
{
  public:
    TimeManager();
    ~TimeManager();

    float getElapsedTime() const;
    float getDeltaTime();

  private:
    sf::Clock _clock;
    sf::Time _time;

    sf::Time restartTimer();
};

#endif //CPP_RTYPE_TIMEMANAGER_HPP
