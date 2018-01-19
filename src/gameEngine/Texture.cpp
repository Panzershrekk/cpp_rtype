//
// Created by grodin on 11/01/18.
//

#include <iostream>
#include <memory>
#include	"Texture.hpp"

Texture::Texture() : _filePath()
{
    this->_texture = std::make_shared<sf::Texture>();
}

Texture::Texture(const std::string &path) :
  _filePath(path)
{
    this->_texture = std::make_shared<sf::Texture>();
    this->_texture->loadFromFile(path);
}

Texture::Texture(const std::string &path, int x, int y, int width, int height) :
_filePath(path)
{
    this->_texture = std::make_shared<sf::Texture>();
    this->_texture->loadFromFile(path, sf::IntRect(x, y, width, height));
}

Texture::~Texture()
= default;

void		Texture::setSmooth(bool active)
{
  this->_texture->setSmooth(active);
}

void		Texture::setRepeated(bool active)
{
  this->_texture->setRepeated(active);
}

std::shared_ptr<sf::Texture> Texture::getSfTexture()
{
  return (this->_texture);
}

const std::string	&Texture::getFilePath(void) const
{
  return (this->_filePath);
}

void Texture::loadFromImage(const sf::Image &img) {
    this->_texture->loadFromImage(img);
}
