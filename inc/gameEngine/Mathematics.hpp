//
// Created by thomas on 10/01/18.
//

#ifndef CPP_RTYPE_MATHEMATICS_HPP
#define CPP_RTYPE_MATHEMATICS_HPP

#include <ostream>
#include <iosfwd>
#include "Position2D.hpp"
#include "Rectangle.hpp"

class Mathematics
{
  public:

    Mathematics();
    ~Mathematics();
    void setPosition(const Position2D& pos);
    void setRectangle(const Rectangle& rect);

    Position2D& getPosition();
    Rectangle& getRectangle();

  private:
    Position2D 	_position;
    Rectangle 	_rect;
};

std::ostream& operator<< (std::ostream& stream, const Position2D& pos);
std::ostream& operator<< (std::ostream& stream, const Rectangle& pos);

#endif //CPP_RTYPE_MATHEMATICS_HPP
