//
// Created by thomas on 17/01/18.
//

#include "EnemyRenderer.hpp"

EnemyRenderer::EnemyRenderer() : _pos(700, 450), _sprite("../assets/Enemy.png")
{
  this->_sprite.setPosition(this->_pos);
}

EnemyRenderer::~EnemyRenderer()
{

}

void EnemyRenderer::update()
{
  simulate();
}

Sprite &EnemyRenderer::getSprite()
{
  return this->_sprite;
}

Position2D EnemyRenderer::getPosition() const
{
  return this->_pos;
}

void EnemyRenderer::simulate()
{
  this->_pos -= Position2D(3, 0);
  this->_sprite.setPosition(this->_pos);
}
