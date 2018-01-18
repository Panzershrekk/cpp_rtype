//
// Created by thomas on 17/01/18.
//

#include <game/EnemyRenderer.hpp>
#include "game/GameRenderer.hpp"

GameRenderer::GameRenderer() : _player(), _clock(), _attackSpeed()
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
      updateEntities();
      this->_clock.restartTimer();
    }
    if (this->_attackSpeed.getElapsedTime() > 0.4)
    {
      if (Keyboard::isKeyPressed(Keyboard::Key::Space))
        this->_player.fire();
      this->_attackSpeed.restartTimer();
    }
    window.clear();
    window.draw(this->_player.getSprite());
    window.draw(e.getSprite());
    drawEntities(window);
    window.display();
  }
}

void GameRenderer::drawEntities(Window & window)
{
    for (auto &it : this->_player.getProjectileVector())
        window.draw(it.getSprite());
    for (auto &it2 : this->_enemies)
      window.draw(it2.getSprite());
}

void GameRenderer::updateEntities()
{
  for (auto &it : this->_player.getProjectileVector())
    it.update();
  for (auto &it2 : this->_enemies)
    it2.update();
}
