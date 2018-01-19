//
// Created by baudet_q on 18/01/18.
//

#include "Star.hpp"

Star::Star(int p_X_Pos, int p_Y_Pos)
{
  xPos = p_X_Pos;
  yPos = p_Y_Pos;
}

int Star::getXPos()
{
  return xPos;
}

int Star::getYPos() const
{
  return yPos;
}

void Star::setXPos(int x)
{
  xPos = x;
}

void Star::setYPos(int y)
{
  yPos = y;
}

void Star::addYPos(int y)
{
  yPos += y;
}

void Star::addXPos(int x)
{
  xPos += x;
}