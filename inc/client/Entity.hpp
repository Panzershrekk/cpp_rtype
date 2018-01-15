//
// Created by Julien Pretet on 11/01/2018.
//

#ifndef CPP_RTYPE_ENTITY_HPP
#define CPP_RTYPE_ENTITY_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class IEntity
{
public:
virtual ~IEntity() {}
  virtual sf::Sprite &getSprite() = 0;
};

template <typename T>
class Entity : public IEntity
{
private:
  T _entity;
public:
  explicit Entity(T entity)
  {
    _entity = entity;
  }
  virtual ~Entity() {}
  sf::Sprite &getSprite() { return _entity;}
};


#endif //CPP_RTYPE_ENTITY_HPP
