#include "SFML/Graphics.hpp"
#include <iostream>
#include <Sprite.hpp>
#include <Window.hpp>
#include <ColliderManager.hpp>
#include <Mouse.hpp>
#include <Player.hpp>
#include <Ennemy.hpp>

int main()
{
  Position2D pos(200, 200);
  ColliderManager collider;
  Window window("hey", 800, 800);
  Sprite sprite("../Sprite-Logo.jpg", pos);

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {

      if (sf::Joystick::isConnected(0))
      {
	if (sf::Joystick::isButtonPressed(0, 1))
	{
	  std::cout << "FIRE" << std::endl;
	}
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	sprite.move(x/5, y/5);
      }
      else
      {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	  sprite.move(-10, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	  sprite.move(0, -10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	  sprite.move(0, 10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	  sprite.move(10, 0);
	}
      }
      switch (event.type)
      {
	case sf::Event::Closed:
	  window.close();

	  break;

      }
    }


    window.clear();
    window.draw(sprite);
    window.display();
  }
}