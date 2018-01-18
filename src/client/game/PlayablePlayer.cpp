//
// Created by thomas on 17/01/18.
//

#include <PlayablePlayer.hpp>
#include <Joystick.hpp>

PlayablePlayer::PlayablePlayer() : _physic(0, 0, 5)
{
  setPosition(Position2D(140, 140));
  //setSprite(Sprite("../assets/Ship_White.png"));
  this->_sprite.setPosition(this->_pos);
}

PlayablePlayer::~PlayablePlayer()
{
}

void PlayablePlayer::update()
{
  if (Joystick::isConnected(0))
  {
    float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

    this->_pos += Position2D(x/this->_physic.getSpeed()/2, y/this->_physic.getSpeed()/2);
  } else
  {
    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
      this->_pos -= Position2D(this->_physic.getSpeed(), 0);
    if (Keyboard::isKeyPressed(Keyboard::Key::Right))
      this->_pos += Position2D(this->_physic.getSpeed(), 0);
    if (Keyboard::isKeyPressed(Keyboard::Key::Up))
      this->_pos -= Position2D(0, this->_physic.getSpeed());
    if (Keyboard::isKeyPressed(Keyboard::Key::Down))
      this->_pos += Position2D(0, this->_physic.getSpeed());
    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
      fire();
  }
  this->_sprite.setPosition(this->_pos);
}

void PlayablePlayer::fire()
{
  std::cout << "" << std::endl;
}
