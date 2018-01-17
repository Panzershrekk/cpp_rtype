//
// Created by thomas on 17/01/18.
//

#ifndef CPP_RTYPE_PLAYABLEPLAYER_HPP
#define CPP_RTYPE_PLAYABLEPLAYER_HPP

#include <Sprite.hpp>
#include <Physic.hpp>
#include <Keyboard.hpp>

class PlayablePlayer
{
  public:
    PlayablePlayer();
    ~PlayablePlayer();
    void update();
    Sprite &getSprite();
    Position2D getPosition() const;

  private:
    Sprite _sprite;
    Physic _physic;
    Position2D _pos;


};

#endif //CPP_RTYPE_PLAYABLEPLAYER_HPP
