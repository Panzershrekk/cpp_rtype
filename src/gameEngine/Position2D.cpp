//
// Created by thomas on 10/01/18.
//

#include <Position2D.hpp>

Position2D::Position2D() : _vector2(0, 0)
{
}

Position2D::Position2D(int x, int y) : _vector2(x, y)
{

}

Position2D::Position2D(const Position2D& pos)
{
  this->_vector2 = pos._vector2;
}

Position2D Position2D::operator+(const Position2D &ovec) const
{
  Position2D result;
  result._vector2 = this->_vector2 + ovec._vector2;
  return (result);
}

Position2D Position2D::operator-(const Position2D &ovec) const
{

  Position2D result;
  result._vector2 = this->_vector2 + ovec._vector2;
  return (result);
}

bool Position2D::operator==(const Position2D &ovec) const
{
  return this->_vector2 == ovec._vector2;
}

bool Position2D::operator!=(const Position2D &ovec) const
{
  return this->_vector2 != ovec._vector2;
}

Position2D Position2D::operator+=(const Position2D &ovec)
{
  this->_vector2 += ovec._vector2;
  return (*this);
}

Position2D Position2D::operator-=(const Position2D &ovec)
{
  this->_vector2 -= ovec._vector2;
  return (*this);
}

int Position2D::getX() const
{
  return (this->_vector2.x);
}

int Position2D::getY() const
{
  return (this->_vector2.y);
}

sf::Vector2<int> Position2D::getVector() const
{
  return (this->_vector2);
}
