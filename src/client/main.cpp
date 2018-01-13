#include "SFML/Graphics.hpp"
#include <iostream>
#include <Sprite.hpp>
#include <Window.hpp>
#include <ColliderManager.hpp>
#include <Mouse.hpp>

int main()
{
  /*sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

  sf::Texture texture;

  if (!texture.loadFromFile("../Sprite-Logo.jpg"))
  {
    std::cout << "Hey dude wtf" << std::endl;
    exit (87);
  }*/


  /*sf::Sprite sprite;
  sprite.setTexture(texture);

  sf::Sprite sprite2;
  sprite2.setTexture(texture);
  sprite2.setPosition(sf::Vector2f(300, 400));*/
  Position2D pos(200, 200);
  ColliderManager collider;
  Window window("hey", 800, 800);
  Sprite sprite("../Sprite-Logo.jpg", pos);
  Sprite sprite2("../Sprite-Logo.jpg", 400, 400);

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      if (Mouse::isButtonPressed(Mouse::Left))
      {
	if (collider.IsMouseOver(sprite, window))
	  std::cout << "clicked" << std::endl;
      }
      switch (event.type)
      {
	case sf::Event::Closed:
	  window.close();

	  break;

      }
    }
    if (collider.IsSpriteColliding(sprite, sprite2))
    {
      std::cout << "The sprite have collided" << std::endl;
      //sprite2.move(sf::Vector2f(0.1, 0));
    }
    else
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
	sprite2.move(-0.1, 0);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
	sprite2.move(0, -0.1);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
	sprite2.move(0, 0.1);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
	sprite2.move(0.1, 0);
      }
      //sprite2.move(sf::Vector2f(0, -0.1));
    }

    window.clear();
    window.draw(sprite);
    window.draw(sprite2);
    window.display();
  }
}