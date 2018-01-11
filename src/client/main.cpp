#include <iostream>
#include "Physic.hpp"
#include "Mathematics.hpp"
#include "Position2D.hpp"

int main()
{
  Position2D p(10,10);
  Position2D x(23, 1);
  Position2D y(x);
  std::cout << x << std::endl;
  std::cout << p << std::endl;
  std::cout << y << std::endl;
  std::cout << x + y << std::endl;
  p += y;
  return 0;
}