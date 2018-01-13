//
// Created by thomas on 13/01/18.
//

#ifndef CPP_RTYPE_COLLIDERMANAGER_HPP
#define CPP_RTYPE_COLLIDERMANAGER_HPP

#include "Sprite.hpp"

class ColliderManager
{
  public:
    ColliderManager();
    ~ColliderManager();

    bool IsSpriteColliding(Sprite& sprite1, Sprite& sprite2);
};

#endif //CPP_RTYPE_COLLIDERMANAGER_HPP
