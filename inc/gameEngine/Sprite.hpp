//
// Created by grodin on 11/01/18.
//

#ifndef CPP_RTYPE_SPRITE_HPP_
#define CPP_RTYPE_SPRITE_HPP_

#include	<SFML/Graphics/Sprite.hpp>
#include	<functional>
#include	"Texture.hpp"
#include	"Position2D.hpp"
#include	"Mouse.hpp"

class Window;

class Sprite
{
  private:
    sf::Sprite		_sprite;
    Texture		_texture;
    Position2D		_pos;
   // ColliderManager	_collider;

  public:
    explicit Sprite();
    Sprite(const std::string &);
    Sprite(const std::string &, float x, float y);
    Sprite(const std::string &, Position2D &pos);
    Sprite(const std::string &, int, int, int, int);
    ~Sprite();
    Texture	getTexture(void) const;
    void 	setTexture(Texture &);
    void 	move(float, float);
    sf::Sprite	getSfSprite(void) const;

    Position2D getPosition(void) const;
    void setPosition(Position2D&);
    void setScale(float, float);
    void move(Position2D&);

    bool isMouseOver(Window &);
    void onClick(std::function<void(void)>, Window &);
};


#endif /* !CPP_RTYPE_SPRITE_HPP_ */
