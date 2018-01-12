#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "RenderSystem.hpp"
#include "Entity.hpp"
#include "MainSystem.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
  MainSystem mSystem;
  RenderSystem renderSystem(window);

  // run the program as long as the window is open
  sf::Texture texture;
  if (!texture.loadFromFile("/Users/blue/Downloads/rem.png", sf::IntRect(0, 0, 10, 10)))
  {
    std::cout << "err load sprite" << std::endl;
    // erreur...
  }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(10, 10)); // absolute position
    std::shared_ptr<IEntity> ptr = std::make_shared<Entity<sf::Sprite>>(sprite);

  renderSystem.addEntity(ptr);
  while (window.isOpen())
  {
    window.clear();
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
	window.close();
    }
    renderSystem.update();
    window.display();
  }

  return 0;
}