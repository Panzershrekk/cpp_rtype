//
// Created by thomas on 16/01/18.
//

#ifndef CPP_RTYPE_AENTITY_HPP
#define CPP_RTYPE_AENTITY_HPP

#include "Position2D.hpp"
#include "Physic.hpp"
#include "Rectangle.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

class AEntity
{
protected:
    int         _id;
    Position2D  _pos;
    Position2D  _hitboxSize;
    Physic      _physic;
    Rectangle   _rect;

public:
    AEntity();
    ~AEntity();
    void setPosition(Position2D &);
    Position2D& getPosition();
    Rectangle & getRectangle();

    int getId() const;

    virtual void update() = 0;

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
        ar & _id;
        ar & _pos;
        ar & _hitboxSize;
        ar & _physic;
        ar & _rect;
    }
};

#endif //CPP_RTYPE_AENTITY_HPP
