#include "Physic.hpp"

Physic::Physic()
{
  this->_speed = 0;
  this->_rotateSpeed = 0;
  this->_gravity = 0;
}

Physic::~Physic()
{
}

Physic::Physic(int gravity, unsigned rotateSpeed, unsigned speed)
{
  this->_speed = speed;
  this->_rotateSpeed = rotateSpeed;
  this->_gravity = gravity;
}

void Physic::setGravity(int gravity)
{
  this->_gravity = gravity;
}

void Physic::setRotateSpeed(unsigned int rotateSpeed)
{
  this->_rotateSpeed = rotateSpeed;
}

void Physic::setSpeed(unsigned int speed)
{
  this->_speed = speed;
}

int Physic::getGravity() const
{
  return (this->_gravity);
}

unsigned int Physic::getRotateSpeed() const
{
  return (this->_rotateSpeed);
}

unsigned int Physic::getSpeed() const
{
  return (this->_speed);
}

std::ostream& operator<<(std::ostream &stream, const Physic &physic)
{
  stream << "Speed is: " << physic.getSpeed() << " RotationSpeed is: "
	 << physic.getRotateSpeed() << " and gravity: " << physic.getGravity();
  return (stream);
}