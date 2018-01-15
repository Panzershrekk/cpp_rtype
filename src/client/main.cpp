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
  Player p;
  Ennemy e;

  std::cout << p.getHp() << std::endl;
  std::cout << e.getHp() << std::endl;
}