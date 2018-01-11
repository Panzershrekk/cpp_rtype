//
// Created by thomas on 11/01/18.
//

#ifndef CPP_RTYPE_RECTANGLE_HPP
#define CPP_RTYPE_RECTANGLE_HPP

#include <SFML/Graphics/Rect.hpp>
#include "Position2D.hpp"

class Rectangle
{
  public:
    Rectangle();
    ~Rectangle();
    Rectangle(int left, int top, int width, int height);
    Rectangle(const Rectangle &);

    bool contains(int x, int y);
    bool contains(const Position2D&);
    bool intersects(const Rectangle &) const;
    bool intersects(const Rectangle &, Rectangle&) const;

    sf::IntRect getIntRect() const;

  private:
    sf::IntRect _rect;
};

#endif //CPP_RTYPE_RECTANGLE_HPP
