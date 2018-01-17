//
// Created by Julien Pretet on 11/01/2018.
//

#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

std::vector<std::shared_ptr<IEntity>>& Renderer::getEntity() {
  return _entity;
}

void Renderer::addEntity(std::shared_ptr<IEntity> &ptr)
{
  _entity.push_back(ptr);
}

void Renderer::removeEntity(std::shared_ptr<IEntity> &ptr)
{
  for (auto it = _entity.begin(); it != _entity.end(); )
  {
    if (*it == ptr)
      _entity.erase(it);
  }
}
