#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

#include "Window.hpp"
#include "Color.hpp"

int main()
{
//  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  Window window("bite", 800, 600);
  Sprite sprite("../Sprite-Logo.jpg");

  // run the program as long as the window is open
  int x = 0;
  while (window.isOpen())
  {
    window.clear();
    // check all the window's events that were triggered since the last iteration of the loop

    sprite.move(x++, 0);
    window.draw(sprite);
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
	window.close();
    }
    window.display();
  }

  return 0;
}