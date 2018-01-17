//
// Created by thomas on 17/01/18.
//


#include <Enemy.hpp>
#include <game/EnemyRenderer.hpp>
#include "game/GameRenderer.hpp"

GameRenderer::GameRenderer() : _player(), _clock()
{

}

GameRenderer::~GameRenderer()
{

}

void GameRenderer::startGame()
{
  Window window("RTYPE", 1200, 1200);
  EnemyRenderer e;

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      switch (event.type)
      {
	case sf::Event::Closed:
	  window.close();

	  break;
      }
    }
    if (this->_clock.getElapsedTime() > 1.0 / 60)
    {
      this->_player.update();
      e.update();
      this->_clock.restartTimer();
    }
    window.clear();
    window.draw(this->_player.getSprite());
    window.draw(e.getSprite());
    window.display();
  }
}
