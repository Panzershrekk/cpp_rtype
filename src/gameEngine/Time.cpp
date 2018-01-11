//
// Created by thomas on 11/01/18.
//

#include <Time.hpp>

float Time::asSeconds() const
{
  return (this->_time.asSeconds());
}

sf::Int32 Time::asMilliseconds() const
{
  return (this->_time.asMilliseconds());
}

sf::Int64 Time::asMicroseconds() const
{
  return (this->_time.asMilliseconds());
}
