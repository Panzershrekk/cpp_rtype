//
// Created by baudet_q on 18/01/18.
//

#include "Star.hpp"

Star::Star(float p_X_Pos, float p_Y_Pos)
{
  xPos = p_X_Pos;
  yPos = p_Y_Pos;
}

float Star::getXPos() const
{
  return xPos;
}

float Star::getYPos() const
{
  return yPos;
}

void Star::setXPos(float x)
{
  xPos = x;
}

void Star::setYPos(float y)
{
  yPos = y;
}

void Star::addYPos(float y)
{
  yPos += y;
}

void Star::addXPos(float x)
{
  xPos += x;
}