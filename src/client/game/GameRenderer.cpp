//
// Created by thomas on 17/01/18.
//


#include <Enemy.hpp>
#include <gameEngine/Image.hpp>
#include <gameEngine/Music.hpp>
#include <gameEngine/MusicManager.hpp>
#include "game/EnemyRenderer.hpp"
#include "client/game/Starfield.hpp"
#include "game/GameRenderer.hpp"

GameRenderer::GameRenderer() : _player(), _clock(), _attackSpeed()
{

}

GameRenderer::~GameRenderer()
{

}

void GameRenderer::startGame()
{
    int xSize = 1200;
    int ySize = 1200;
    Window window("RTYPE", 1200, 1200);
    EnemyRenderer e;

  /* STARFIELD */
    Image starsImage;
  Color c(0, 0, 0);
    starsImage.create(xSize, ySize, c.getColor().Black);

    Texture starsTexture;
    starsTexture.loadFromImage(starsImage.getImage());

    Sprite starsSprite;
    starsSprite.setTexture(starsTexture);

    Position2D p(0, 0);
    //starsSprite.setPosition(0,0);
    starsSprite.setPosition(p);

    Starfield backgroundStars(1200, 1200);
/* starfield */

  MusicManager m;
  Music music("../resources/MainMenu.ogg", "MainMenu");
  m.AddNewMusic(music);
  m.getMusicByName("MainMenu").playAudio();
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
      this->_player.forbiddenMove(window);
      backgroundStars.updateStarfield();
      this->_clock.restartTimer();
    }
      starsTexture.loadFromImage(starsImage.getImage());
      backgroundStars.drawStarfield(*starsTexture.getSfTexture());

    window.clear();

    window.draw(starsSprite);

    if (this->_attackSpeed.getElapsedTime() > 0.4)
    {
      if (Keyboard::isKeyPressed(Keyboard::Key::Space))
        this->_player.fire();
      this->_attackSpeed.restartTimer();
    }

    window.draw(this->_player.getSprite());
    window.draw(e.getSprite());
    //drawProjectile(window);
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
