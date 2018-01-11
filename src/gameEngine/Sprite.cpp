//
// Created by grodin on 11/01/18.
//

#include "Sprite.hpp"

Sprite::Sprite() : _sprite()
{
}

Sprite::Sprite(const std::string &path) : _sprite(),
  _texture(path)
{
  sf::Texture	*text = new sf::Texture();

  text->loadFromFile("../Sprite-Logo.jpg");
  this->_sprite.setTexture(*text);
}

Sprite::Sprite(const std::string &path, int x, int y, int width, int height) :
  _sprite(sf::Texture()),
  _texture(path, x, y, width, height)
{
  sf::Texture tmpTexture;

  tmpTexture.loadFromFile(path, sf::IntRect(x, y, width, height));
  this->_sprite.setTexture(tmpTexture);
}

Sprite::~Sprite()
{
}

Texture		Sprite::getTexture() const
{
  return (this->_texture);
}

void 		Sprite::setTexture(Texture &texture)
{
  this->_sprite.setTexture(texture.getSfTexture());
}

void 		Sprite::move(float x, float y)
{
  this->_sprite.move(x, y);
}

sf::Sprite	Sprite::getSfSprite(void) const
{
  return (this->_sprite);
}

