#include "SFML/Graphics.hpp"
#include <iostream>
#include <Window.hpp>
#include "MainMenu.hpp"
#include "Window.hpp"

int main()
{
  Window window("hey", 800, 800);
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
  /*Window window("hey", 800, 800);
  MainSystem mSystem;
  RenderSystem renderSystem(window.getRenderWindow());
  Position2D pos(200, 200);
  Sprite sprite("../Sprite-Logo.jpg", pos);


  std::shared_ptr<IEntity> ptr = std::make_shared<Entity<Sprite>>(sprite);
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
  }*/

  return 0;
}