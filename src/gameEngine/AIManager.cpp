//
// Created by thomas on 12/01/18.
//

#include <AIManager.hpp>

AIManager::AIManager()
{
}

AIManager::~AIManager()
{
}

Position2D& AIManager::PredefinedRightToLeft(Position2D &pos, int speed)
{
  Position2D pos2(speed, 0);

  pos -= pos2;
  return (pos);
}

Position2D &AIManager::PredefinedBottomToTop(Position2D &pos, int speed)
{
  Position2D pos2(0, speed);

  pos += pos2;
  return (pos);
}
