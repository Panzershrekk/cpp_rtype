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

  text->loadFromFile(path);
  this->_sprite.setTexture(*text);
}

Sprite::Sprite(const std::string &path, float x, float y) :_sprite(), _texture(path)
{
  sf::Texture	*text = new sf::Texture();

  text->loadFromFile(path);
  this->_sprite.setTexture(*text);
  this->_pos = Position2D(x, y);
  this->_sprite.setPosition(this->_pos.getVector().x, this->_pos.getVector().y);
}


Sprite::Sprite(const std::string &path, Position2D &pos) :_sprite(), _texture(path)
{
  sf::Texture	*text = new sf::Texture();

  text->loadFromFile(path);
  this->_sprite.setTexture(*text);
  this->_pos = pos;
  this->_sprite.setPosition(pos.getVector().x, pos.getVector().y);
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

Position2D Sprite::getPosition(void) const
{
  return (this->_pos);
}

void Sprite::setPosition(Position2D &pos)
{
  this->_pos = pos;
  this->_sprite.setPosition(pos.getVector().x, pos.getVector().y);
}

void Sprite::setScale(float x, float y)
{
  this->_sprite.setScale(x, y);
}

void Sprite::move(Position2D &pos)
{
  this->_pos = pos;
  this->_sprite.move(pos.getVector().x, pos.getVector().y);

}

bool Sprite::isMouseOver(Window& win)
{
  return this->_sprite.getGlobalBounds().contains(Mouse::getPosition(win).getVector());
}

void Sprite::onClick(std::function<void(Window &, sf::Event &)> f, Window &win, sf::Event &event)
{
  if (Mouse::isButtonPressed(Mouse::Left) && isMouseOver(win))
  {
    f(win, event);
  }
}