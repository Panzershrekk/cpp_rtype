//
// Created by baudet_q on 18/01/18.
//

#include "Star.hpp"

Star::Star(sf::Uint16 p_X_Pos, sf::Uint16 p_Y_Pos)
{
  xPos = p_X_Pos;
  yPos = p_Y_Pos;
}

sf::Uint16 Star::getXPos()
{
  return xPos;
}

sf::Uint16 Star::getYPos() const
{
  return yPos;
}

void Star::setXPos(sf::Uint16 x)
{
  xPos = x;
  return;
}

void Star::setYPos(sf::Uint16 y)
{
  yPos = y;
  return;
}

void Star::addYPos(sf::Uint16 y)
{
  yPos += y;
  return;
}

void Star::addXPos(sf::Uint16 x)
{
  xPos += x;
  return;
}