//
// Created by thomas on 17/01/18.
//

#ifndef CPP_RTYPE_GAMERENDERER_HPP
#define CPP_RTYPE_GAMERENDERER_HPP

#include <Window.hpp>
#include <SFML/Window/Event.hpp>
#include <TimeManager.hpp>
#include "PlayablePlayer.hpp"

class GameRenderer
{
  public:
    GameRenderer();
    ~GameRenderer();
    void startGame();

  private:
    PlayablePlayer _player;
    TimeManager _clock;

};

#endif //CPP_RTYPE_GAMERENDERER_HPP