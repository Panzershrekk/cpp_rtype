//
// Created by thomas on 13/01/18.
//

#ifndef CPP_RTYPE_COLLIDERMANAGER_HPP
#define CPP_RTYPE_COLLIDERMANAGER_HPP

#include "Mouse.hpp"
#include "Rectangle.hpp"

class ColliderManager
{
  public:
    ColliderManager();
    ~ColliderManager();

    bool IsSpriteColliding(Sprite& sprite1, Sprite& sprite2);
    bool IsRectangleColliding(Rectangle& rec1, Rectangle& rec2);

  //  bool IsMouseOver(Sprite& sprite, Window& win);
};

#endif //CPP_RTYPE_COLLIDERMANAGER_HPP
