//
// Created by thomas on 13/01/18.
//

#include <ColliderManager.hpp>

ColliderManager::ColliderManager()
{
}

ColliderManager::~ColliderManager()
{
}

bool ColliderManager::IsSpriteColliding(Sprite &sprite1, Sprite &sprite2)
{
  return (sprite1.getSfSprite().getGlobalBounds().intersects(sprite2.getSfSprite().getGlobalBounds()));
}
