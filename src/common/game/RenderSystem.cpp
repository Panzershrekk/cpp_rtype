//
// Created by Julien Pretet on 11/01/2018.
//

#include "RenderSystem.hpp"

RenderSystem::RenderSystem(sf::RenderWindow& target) : _display(target)
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::update()
{
  for (auto &entity : renderer.getEntity())
  {
    _display.draw(entity->getSprite().getSfSprite());
  }
}

void RenderSystem::addEntity(std::shared_ptr<IEntity> &ptr)
{
  renderer.addEntity(ptr);
}

void RenderSystem::removeEntity(std::shared_ptr<IEntity> &ptr)
{
  renderer.removeEntity(ptr);
}
