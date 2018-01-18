//
// Created by thomas on 17/01/18.
//

#include "AEntityRenderer.hpp"

AEntityRenderer::AEntityRenderer()
{

}

AEntityRenderer::AEntityRenderer(const std::string & path) : _sprite(path)
{

}


AEntityRenderer::~AEntityRenderer()
{

}

Sprite &AEntityRenderer::getSprite()
{
  return (this->_sprite);
}

Position2D AEntityRenderer::getPosition() const
{
  return (this->_pos);
}

void AEntityRenderer::setPosition(const Position2D &pos)
{
  this->_pos = pos;
}

/*void AEntityRenderer::setSprite(const Sprite sprite) : _sprite(sprite)
{
}*/