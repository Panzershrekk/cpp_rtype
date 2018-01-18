//
// Created by thomas on 17/01/18.
//

#include "game/EnemyRenderer.hpp"

EnemyRenderer::EnemyRenderer() : _pos(700, 450), _sprite("../assets/Enemy.png")
{
  /*setPosition(Position2D(700, 140));
  setSprite(Sprite("../assets/Ship_White.png"));*/
  this->_sprite.setPosition(this->_pos);
}

EnemyRenderer::~EnemyRenderer()
{

}

void EnemyRenderer::update()
{
  simulate();
}

void EnemyRenderer::simulate()
{
  this->_pos -= Position2D(3, 0);
  this->_sprite.setPosition(this->_pos);
}
