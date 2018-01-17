//
// Created by thomas on 16/01/18.
//

#ifndef CPP_RTYPE_AENTITY_HPP
#define CPP_RTYPE_AENTITY_HPP

#include <Position2D.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <Physic.hpp>

class AEntity
{
  public:
    AEntity();
    void setPosition(Position2D &);
    Position2D getPosition() const;

  protected:
    Position2D _pos;
    Physic _physic;
};

#endif //CPP_RTYPE_AENTITY_HPP
