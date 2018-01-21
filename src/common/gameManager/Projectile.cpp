//
// Created by thomas on 16/01/18.
//

#include <Projectile.hpp>

Projectile::Projectile(const Position2D &pos)
{
  this->_physic.setSpeed(5);
  this->_hitboxSize = Position2D(7, 6);
  this->_rect = Rectangle(this->_pos.getX() - this->_hitboxSize.getX(), this->_pos.getY() - this->_hitboxSize.getY(), 14, 12);
  this->_pos = pos;
}

Projectile::~Projectile()
{

}

void Projectile::update()
{
  this->_ai.PredefinedLeftToRight(this->_pos, this->_physic.getSpeed());
  //this->_rect.changeTopLeft(this->_hitboxSize);
  Position2D p(Position2D(this->_pos.getX() - this->_hitboxSize.getX(), this->_pos.getY() - this->_hitboxSize.getY()));
  this->_rect.changeTopLeft(p);
}
