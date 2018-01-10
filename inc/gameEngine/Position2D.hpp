//
// Created by thomas on 10/01/18.
//

#ifndef CPP_RTYPE_POSITION2D_HPP
#define CPP_RTYPE_POSITION2D_HPP

#include <SFML/System/Vector2.hpp>

class Position2D
{
  public:
    Position2D();
    Position2D(int, int);
    Position2D(const Position2D&);

  private:
    sf::Vector2 _vector2;

};

#endif //CPP_RTYPE_POSITION2D_HPP
