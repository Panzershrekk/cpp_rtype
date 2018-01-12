//
// Created by grodin on 11/01/18.
//

#include <iostream>
#include "Font.hpp"

Font::Font() : _fontPath("")
{
  this->_font = new sf::Font();
}

Font::Font(const std::string &path) : _fontPath(path)
{
  this->_font = new sf::Font();

  this->_font->loadFromFile(path);
  std::cout << "Construct Font" << std::endl;
}

Font::~Font()
{
  delete(this->_font);
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

sf::Font	Font::getSfFont()
{
  return (*this->_font);
}