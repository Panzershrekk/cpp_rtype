//
// Created by thomas on 12/01/18.
//

#include <Mouse.hpp>

bool Mouse::isButtonPressed(Button button)
{
  sf::Mouse::Button x = static_cast<sf::Mouse::Button >(button);
  return (sf::Mouse::isButtonPressed(x));
}

Position2D Mouse::getPosition()
{
  static sf::Vector2i pos;
  pos = sf::Mouse::getPosition();
  return Position2D(pos.x, pos.y);
}

void Mouse::setPosition(const Position2D &position)
{

}

Position2D Mouse::getPosition(Window &relativeTo)
{
  static sf::Vector2i pos;
  pos = sf::Mouse::getPosition(relativeTo.getRenderWindow());
  return (Position2D(pos.x, pos.y));
}
