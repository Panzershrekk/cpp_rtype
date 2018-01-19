//
// Created by Julien Pretet on 11/01/2018.
//

#ifndef CPP_RTYPE_RENDERER_HPP
#define CPP_RTYPE_RENDERER_HPP

#include <vector>
#include <memory>
#include "Entity.hpp"

class Renderer
{
private:
  std::vector<std::shared_ptr<IEntity>> _entity;
public:
  Renderer();
  ~Renderer();

  std::vector<std::shared_ptr<IEntity>>& getEntity();
  void addEntity(std::shared_ptr<IEntity>&);
  void removeEntity(std::shared_ptr<IEntity>&);
};


#endif //CPP_RTYPE_RENDERER_HPP
