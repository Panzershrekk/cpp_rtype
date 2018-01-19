//
// Created by grodin on 11/01/18.
//

#include <iostream>
#include "Text.hpp"

Text::Text() : _text(), _str()
{
  this->_font = new Font();
}

Text::Text(const std::string &string, const std::string &fontPath) : _text(), _str(string)
{
  this->_font = new Font(fontPath);

  this->_text.setFont(*this->_font->getSfFont());
  this->_text.setString(string);
}

Text::Text(const std::string &string, const std::string &fontPath, float x, float y) : _str(string)
{
  this->_font = new Font(fontPath);

  this->_text.setFont(*this->_font->getSfFont());
  this->_text.setString(string);
  this->_text.setPosition(x, y);
}

Text::~Text()
{
  delete(this->_font);
}

void		Text::setFont(const std::string &fontPath)
{
  this->_font->setFontPath(fontPath);
  this->_text.setFont(*this->_font->getSfFont());
}

void 		Text::setString(const std::string &newString)
{
  this->_str = newString;
  this->_text.setString(newString);
}

void 		Text::setCharacterSize(unsigned int size)
{
  this->_text.setCharacterSize(size);
}

void 		Text::setPosition(int x, int y)
{
  this->_text.setPosition(sf::Vector2f(x, y));
}

void 		Text::setScale(int scaleX, int scaleY)
{
  this->_text.setScale(sf::Vector2f(scaleX, scaleY));
}

sf::Text	&Text::getSfText()
{
  return (this->_text);
}

std::string	Text::getString() const
{
  return (this->_str);
}