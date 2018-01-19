//
// Created by grodin on 11/01/18.
//

#include <iostream>
#include "Font.hpp"

Font::Font() : _fontPath("")
{
  this->_font = std::make_shared<sf::Font>();
}

Font::Font(const std::string &path) : _fontPath(path)
{
  this->_font = std::make_shared<sf::Font>();
  this->_font->loadFromFile(path);
}

Font::~Font()
{
}

void		Font::setFontPath(const std::string &nPath)
{
  this->_fontPath = nPath;
  this->_font->loadFromFile(nPath);
}

std::string	Font::getFontPath() const
{
  return (this->_fontPath);
}

std::shared_ptr<sf::Font>	Font::getSfFont()
{
  return (this->_font);
}