//
// Created by thomas on 10/01/18.
//

#ifndef CPP_RTYPE_MATHEMATICS_HPP
#define CPP_RTYPE_MATHEMATICS_HPP

#include <ostream>
#include <iosfwd>
#include "Position2D.hpp"

class Mathematics
{
  public:

    Mathematics();
    ~Mathematics();
    void setPosition(const Position2D& pos);
    Position2D& getPosition();

  private:
    Position2D _position;
};

std::ostream& operator<< (std::ostream& stream, const Position2D& pos);

#endif //CPP_RTYPE_MATHEMATICS_HPP
