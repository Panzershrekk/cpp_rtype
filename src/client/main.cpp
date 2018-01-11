#include <iostream>
#include <SFML/System/Clock.hpp>
#include "Physic.hpp"
#include "Mathematics.hpp"
#include "Window.hpp"
#include "Sprite.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

#include "Window.hpp"
#include "Color.hpp"

#include "TimeManager.hpp"

int main()
{

  /*Window window("bite", 800, 600);
  Sprite sprite("../Sprite-Logo.jpg");

  // run the program as long as the window is open
  int x = 0;
  while (window.isOpen())
  {
    window.clear();
    // check all the window's events that were triggered since the last iteration of the loop

    window.draw(sprite);
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
	window.close();
    }
    window.display();
  }*/
  TimeManager manger;
  while (true)
  {
    if (manger.getElapsedTime() > 1.0f)
    {
      std::cout << "Yolo world" << std::endl;
      manger.restartTimer();
    }
  }
  return 0;
}