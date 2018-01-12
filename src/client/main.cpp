#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

#include "Physic.hpp"
#include "Mathematics.hpp"
#include "Window.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

int main()
{

//  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  Window window("Window", 800, 600);
  Text	text("Thomas suce", "../Triumph-wheels-rough.ttf");

  // run the program as long as the window is open
  int x = 0;
  while (window.isOpen())
  {
    window.clear();
    // check all the window's events that were triggered since the last iteration of the loop
    window.draw(text);
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