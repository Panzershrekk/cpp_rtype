//
// Created by thomas on 12/01/18.
//

#include <Joystick.hpp>

bool Joystick::isConnected(unsigned int joystick)
{
  return (sf::Joystick::isConnected(0));
}

unsigned int Joystick::getButtonCount(unsigned int joystick)
{
  return (sf::Joystick::getButtonCount(joystick));
}

bool Joystick::hasAxis(unsigned int joystick, Axis axis)
{
  return (false);
}

bool Joystick::isButtonPressed(unsigned int joystick, unsigned int button)
{
  return (sf::Joystick::isButtonPressed(joystick, button));
}

float Joystick::getAxisPosition(unsigned int joystick, Axis axis)
{
  return 0;
}


void Joystick::update()
{
  sf::Joystick::update();
}
