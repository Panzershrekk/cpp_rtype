//
// Created by thomas on 12/01/18.
//

#ifndef CPP_RTYPE_AIMANAGER_HPP
#define CPP_RTYPE_AIMANAGER_HPP

#include "Position2D.hpp"

class AIManager
{
  public:
    AIManager();
    ~AIManager();

    Position2D& PredefinedRightToLeft(Position2D &, int speed);
    Position2D& PredefinedLeftToRight(Position2D &, int speed);
    Position2D& PredefinedBottomToTop(Position2D &, int speed);
    Position2D& PredefinedRightToLeftSinus(Position2D &, int speed);
    Position2D& PredefinedLeftToRightSinus(Position2D &, int speed);
};

#endif //CPP_RTYPE_AIMANAGER_HPP
