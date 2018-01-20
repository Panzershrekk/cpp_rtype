//
// Created by thomas on 17/01/18.
//

#include <gameEngine/AIManager.hpp>
#include "game/EnemyRenderer.hpp"

EnemyRenderer::EnemyRenderer() : AEntityRenderer("../assets/Enemy.png")
{
  setPosition(Position2D(700, 140));
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
  AIManager ai;
  ai.PredefinedRightToLeftSinus(this->_pos, 3);
  this->_sprite.setPosition(this->_pos);
}
