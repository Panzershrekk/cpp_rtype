//
// Created by thomas on 17/01/18.
//


#include "GameRenderer.hpp"

GameRenderer::GameRenderer() : _player(), _clock()
{

}

GameRenderer::~GameRenderer()
{

}

void GameRenderer::startGame()
{
  Window window("RTYPE", 1200, 1200);

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
      this->_clock.restartTimer();
    }
    window.clear();
    window.draw(this->_player.getSprite());
    window.display();
  }
}
