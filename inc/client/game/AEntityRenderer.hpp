//
// Created by thomas on 17/01/18.
//

#ifndef CPP_RTYPE_AENTITYRENDERER_HPP
#define CPP_RTYPE_AENTITYRENDERER_HPP

#include <Sprite.hpp>

class AEntityRenderer
{
  public:
    AEntityRenderer();
    virtual ~AEntityRenderer();

    Sprite &getSprite();
    Position2D getPosition() const;

    void setPosition(const Position2D&);
    void setSprite(const Sprite);

    virtual void update() = 0;
  protected:
    Sprite _sprite;
    Position2D _pos;
};

#endif //CPP_RTYPE_AENTITYRENDERER_HPP
