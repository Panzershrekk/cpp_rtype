//
// Created by thomas on 12/01/18.
//

#include "Keyboard.hpp"

bool Keyboard::isKeyPressed(Key k)
{
  sf::Keyboard::Key x = static_cast<sf::Keyboard::Key >(k);
  return (sf::Keyboard::isKeyPressed(x));
}
