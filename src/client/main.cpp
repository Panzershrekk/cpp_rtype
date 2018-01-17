#include "SFML/Graphics.hpp"
#include <iostream>
#include <Window.hpp>
#include <game/GameRenderer.hpp>
#include "MainMenu.hpp"
#include "Window.hpp"

int main()
{
  GameRenderer gameRenderer;
  gameRenderer.startGame();
  return (0);
}