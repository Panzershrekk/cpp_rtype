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

void Mathematics::setRectangle(const Rectangle &rect)
{
  this->_rect = rect;
}

Rectangle &Mathematics::getRectangle()
{
  return (this->_rect);
}

std::ostream& operator<<(std::ostream &stream, const Position2D &pos)
{
  stream << "X is: " << pos.getX() << " and Y: " << pos.getY();
  return (stream);
}

std::ostream& operator<<(std::ostream &stream, const Rectangle &rec)
{
  stream << "Height is: " << rec.getIntRect().height << " and width: " << rec.getIntRect().width
	 << " top is: " << rec.getIntRect().top << " and left: " << rec.getIntRect().left;
  return (stream);
}