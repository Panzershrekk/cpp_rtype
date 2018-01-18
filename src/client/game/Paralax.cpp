//
// Created by baudet_q on 17/01/18.
//

#include <iostream>
#include "Paralax.hpp"

Paralax::Paralax() = default;

Paralax::~Paralax() = default;

void Paralax::update(Position2D p)
{
  this->_pos += p;

}

Position2D Paralax::getPos() const
{
  return (Position2D());
}

void Paralax::setPos(Position2D pos)
{
  this->_pos = pos;
}

void Paralax::setBackground(Sprite sprite)
{
  this->_background = sprite;
}

Sprite Paralax::getBackground() const
{
  return Sprite();
}


