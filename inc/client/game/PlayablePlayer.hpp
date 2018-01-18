//
// Created by thomas on 17/01/18.
//

#ifndef CPP_RTYPE_PLAYABLEPLAYER_HPP
#define CPP_RTYPE_PLAYABLEPLAYER_HPP

#include <Sprite.hpp>
#include <Physic.hpp>
#include <Keyboard.hpp>
#include <iostream>
#include "AEntityRenderer.hpp"

class PlayablePlayer : public AEntityRenderer
{
  public:
    PlayablePlayer();
    ~PlayablePlayer();
    void fire();
    void update();

  private:
    Physic _physic;


};

#endif //CPP_RTYPE_PLAYABLEPLAYER_HPP
