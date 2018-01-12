//
// Created by thomas on 11/01/18.
//

#include <Rectangle.hpp>

Rectangle::Rectangle() : _rect(0, 0, 0, 0)
{

}

Rectangle::~Rectangle()
{

}

Rectangle::Rectangle(int left, int top, int width, int height) : _rect(left, top, width, height)
{

}

Rectangle::Rectangle(const Rectangle & rect)
{
  this->_rect = rect._rect;
}

bool Rectangle::contains(int x, int y)
{
  return (this->_rect.contains(x, y));
}

bool Rectangle::contains(const Position2D &pos)
{
  return (this->_rect.contains(pos.getVector()));
}

bool Rectangle::intersects(const Rectangle &rec) const
{
  return (this->_rect.intersects(rec._rect));
}

bool Rectangle::intersects(const Rectangle &rec, Rectangle &rec2) const
{
  return (this->_rect.intersects(rec._rect, rec2._rect));
}

sf::IntRect Rectangle::getIntRect() const
{
  return (this->_rect);
}

