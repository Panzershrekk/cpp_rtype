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
#include "AIManager.hpp"

int main()
{
  TimeManager manger;
  AIManager iam;
  Position2D pos(400, 200);
  float dTime;

  while (true)
  {
    if (manger.getElapsedTime() > 1.0f)
    {
      pos = iam.PredefinedRightToLeft(pos, 10);
      std::cout << pos << std::endl;
      dTime = manger.getDeltaTime();
    }
  }
  return 0;
}