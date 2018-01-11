//
// Created by thomas on 10/01/18.
//

#include <Mathematics.hpp>

Mathematics::Mathematics()
{

}

Mathematics::~Mathematics()
{

}

void Mathematics::setPosition(const Position2D &pos)
{
  this->_position = pos;
}

Position2D &Mathematics::getPosition()
{
  return (this->_position);
}

std::ostream& operator<<(std::ostream &stream, const Position2D &pos)
{
  stream << "X is: " << pos.getX() << " and Y: " << pos.getY();
  return (stream);
}