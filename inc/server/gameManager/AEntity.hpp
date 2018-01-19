//
// Created by thomas on 16/01/18.
//

#ifndef CPP_RTYPE_AENTITY_HPP
#define CPP_RTYPE_AENTITY_HPP

#include "Position2D.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <Physic.hpp>
#include <Rectangle.hpp>

class AEntity
{
  public:
    AEntity();
    virtual ~AEntity();

    void setPosition(Position2D &);
    Position2D& getPosition();
    int getId() const;

    virtual void update() = 0;

  protected:
    int _id;
    Position2D _pos;
    Position2D _hitboxSize;
    Physic _physic;
    Rectangle _rect;
};

#endif //CPP_RTYPE_AENTITY_HPP
