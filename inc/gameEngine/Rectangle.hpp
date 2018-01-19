//
// Created by thomas on 11/01/18.
//

#ifndef CPP_RTYPE_RECTANGLE_HPP
#define CPP_RTYPE_RECTANGLE_HPP

#include <SFML/Graphics/Rect.hpp>
#include "Position2D.hpp"

class Rectangle
{
private:
    sf::IntRect _rect;

  public:
    Rectangle();
    ~Rectangle();
    Rectangle(int left, int top, int width, int height);
    Rectangle(const Rectangle &);

    void changeTopLeft(Position2D& pos);
    bool contains(int x, int y);
    bool contains(const Position2D&);
    bool intersects(const Rectangle &) const;
    bool intersects(const Rectangle &, Rectangle&) const;

    sf::IntRect getIntRect() const;

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
    }
};

#endif //CPP_RTYPE_RECTANGLE_HPP
