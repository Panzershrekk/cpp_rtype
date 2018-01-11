//
// Created by grodin on 11/01/18.
//

#ifndef CPP_RTYPE_SPRITE_HPP_
#define CPP_RTYPE_SPRITE_HPP_

#include	<SFML/Graphics/Sprite.hpp>
#include	"Texture.hpp"

class Sprite
{
  private:
    sf::Sprite	_sprite;
    Texture	_texture;
//Position2D	_pos;

  public:
    explicit Sprite();
    Sprite(const std::string &);
    Sprite(const std::string &, int, int, int, int);
    ~Sprite();
    Texture	getTexture(void) const;
    void 	setTexture(Texture &);
    void 	move(float, float);
    sf::Sprite	getSfSprite(void) const;
// Position2D getPosition(void) const;
// void setPosition(Position2D);
// void move(Position2D)
};


#endif /* !CPP_RTYPE_SPRITE_HPP_ */
