#include "SFML/Graphics.hpp"
#include <iostream>
#include "client/menu/MainMenu.hpp"
#include "gameEngine/Window.hpp"

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
  Window window("hey", 1920, 1080);
  MainMenu main;

  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {
      main.update(window);
      switch (event.type)
      {
	case sf::Event::Closed:
	  window.close();

	  break;
      }
    }

    window.clear();
    main.draw(window);
    window.display();
  }
}