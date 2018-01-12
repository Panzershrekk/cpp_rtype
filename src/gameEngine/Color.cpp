//
// Created by grodin on 10/01/18.
//

#include	"Color.hpp"

Color::Color() : _color(255, 255, 255)
{
}

Color::Color(int r, int g, int b) : _color(r, g, b)
{
}

Color::Color(int r, int g, int b, int alpha) : _color(r, g, b, alpha)
{
}

Color::~Color()
= default;

int	Color::getRed(void) const
{
  return this->_color.r;
}

int	Color::getGreen(void) const
{
  return this->_color.g;
}

int	Color::getBlue(void) const
{
  return this->_color.b;
}

int	Color::getAlpha(void) const
{
  return this->_color.a;
}