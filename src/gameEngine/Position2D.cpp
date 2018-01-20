//
// Created by thomas on 10/01/18.
//

#include <Position2D.hpp>
#include <iostream>

Position2D::Position2D() : _vector2(0, 0), _x(0), _y(0)
{

}

Position2D::Position2D(int x, int y) : _vector2(x, y), _x(x), _y(y)
{
  //std::cout << "test" << _x << std::endl;
}

Position2D::Position2D(const Position2D& pos)
{
    this->_vector2 = pos._vector2;
    this->_x = pos._x;
    this->_y = pos._y;
}

Position2D Position2D::operator+(const Position2D &ovec) const
{
    Position2D result;
    result._vector2 = this->_vector2 + ovec._vector2;
    result._x = this->_x + ovec._x;
    result._y = this->_y + ovec._y;
    return (result);
}

Position2D Position2D::operator-(const Position2D &ovec) const
{

    Position2D result;
    result._vector2 = this->_vector2 - ovec._vector2;
    result._x = this->_x - ovec._x;
    result._y = this->_y - ovec._y;
    return (result);
}

bool Position2D::operator==(const Position2D &ovec) const
{
    return (ovec.getX() == this->getX() && ovec.getY() == this->getY());
}

bool Position2D::operator!=(const Position2D &ovec) const
{
    return !(ovec == *this);
}

Position2D Position2D::operator+=(const Position2D &ovec)
{
    this->_vector2 += ovec._vector2;
    this->_x += ovec._x;
    this->_y += ovec._y;
    return (*this);
}

Position2D Position2D::operator-=(const Position2D &ovec)
{
    this->_vector2 -= ovec._vector2;
    this->_x -= ovec._x;
    this->_y -= ovec._y;
    return (*this);
}

int Position2D::getX() const
{
  //std::cout << "GETT" << this->_x << std::endl;
    return (this->_x);
  //return (this->_vector2.x);
}

int Position2D::getY() const
{
  //return (this->_vector2.y);
  return (this->_y);
}

sf::Vector2<float> Position2D::getVector() const
{
    return (this->_vector2);
}