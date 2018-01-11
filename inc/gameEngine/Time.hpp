//
// Created by thomas on 11/01/18.
//

#ifndef CPP_RTYPE_TIME_HPP
#define CPP_RTYPE_TIME_HPP

#include <SFML/System/Time.hpp>

class Time
{
  public:
    Time() {};
    ~Time() {};

    float asSeconds() const;
    sf::Int32 asMilliseconds () const;
    sf::Int64 asMicroseconds () const;

  private:
    sf::Time _time;
};

#endif //CPP_RTYPE_TIME_HPP
