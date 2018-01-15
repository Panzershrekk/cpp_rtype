//
// Created by Julien Pretet on 11/01/2018.
//

#ifndef CPP_RTYPE_RENDERSYSTEM_HPP
#define CPP_RTYPE_RENDERSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include "ISystem.hpp"
#include "Renderer.hpp"

class RenderSystem : public ISystem
{
private:
  Renderer renderer;
  sf::RenderWindow &_display;
public:
  explicit RenderSystem(sf::RenderWindow &target);
  ~RenderSystem();
  void update();
  void addEntity(std::shared_ptr<IEntity> &ptr);
  void removeEntity(std::shared_ptr<IEntity> &ptr);
};

#endif //CPP_RTYPE_RENDERSYSTEM_HPP
