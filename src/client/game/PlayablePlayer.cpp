//
// Created by thomas on 17/01/18.
//

#include <PlayablePlayer.hpp>

PlayablePlayer::PlayablePlayer() : _pos(140, 140), _sprite("../assets/Ship_White.png"), _physic(0, 0, 5)
{
  this->_sprite.setPosition(this->_pos);
}

PlayablePlayer::~PlayablePlayer()
{
}

void PlayablePlayer::update()
{
  if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    this->_pos -= Position2D(this->_physic.getSpeed(), 0);
  if (Keyboard::isKeyPressed(Keyboard::Key::Right))
    this->_pos += Position2D(this->_physic.getSpeed(), 0);
  if (Keyboard::isKeyPressed(Keyboard::Key::Up))
    this->_pos -= Position2D(0, this->_physic.getSpeed());
  if (Keyboard::isKeyPressed(Keyboard::Key::Down))
    this->_pos += Position2D(0, this->_physic.getSpeed());
  this->_sprite.setPosition(this->_pos);
  if (Keyboard::isKeyPressed(Keyboard::Key::Space))
    fire();
}

void PlayablePlayer::fire()
{
  std::cout << "" << std::endl;
}


Sprite &PlayablePlayer::getSprite()
{
  return (this->_sprite);
}

Position2D PlayablePlayer::getPosition() const
{
  return (this->_pos);
}

