//
// Created by Julien Pretet on 11/01/2018.
//

#ifndef CPP_RTYPE_ENTITY_HPP
#define CPP_RTYPE_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "Sprite.hpp"
#include <memory>

class IEntity
{
public:
virtual ~IEntity() {}
  virtual Sprite &getSprite() = 0;
};

template <typename T>
class Entity : public IEntity
{
private:
  T _entity;
public:
  explicit Entity(T &entity) : _entity(entity)
  {
  }
  virtual ~Entity() {}
  Sprite &getSprite() { return _entity;}
};


#endif //CPP_RTYPE_ENTITY_HPP
