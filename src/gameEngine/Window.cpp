//
// Created by grodin on 10/01/18.
//

#include	"Window.hpp"

Window::Window(const std::string &title, unsigned int width, unsigned int height) : _win(sf::VideoMode(width, height), title)
{
}

Window::~Window()
{
}

void Window::close()
{
  this->_win.close();
}

void Window::clear()
{
  this->_win.clear();
}

bool Window::isOpen() const
{
  return (this->_win.isOpen());
}

void Window::setTitle(const std::string &nTitle)
{
  this->_win.setTitle(nTitle);
}

void Window::display()
{
  this->_win.display();
}

bool Window::pollEvent(sf::Event &event)
{
  return (this->_win.pollEvent(event));
}

void Window::draw(Sprite &sprite)
{
  _win.draw(sprite.getSfSprite());
}


/*
void Window::setPosition(const Position2D &nPos)
{
  this->_win.setPosition(nPos->getVector);
}
*/