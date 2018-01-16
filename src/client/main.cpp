#include "MenuWindow.hpp"

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
  MenuWindow menu;

  menu.start();
}