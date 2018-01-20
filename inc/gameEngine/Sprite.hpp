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

  public:
    explicit Sprite();
    Sprite(const std::string &);
    Sprite(const std::string &, float x, float y);
    Sprite(const std::string &, Position2D &pos);
    Sprite(const std::string &, int, int, int, int);
    ~Sprite();

    sf::Sprite	&getSfSprite(void);
    Texture	getTexture(void) const;
    void 	setTexture(Texture &);
    void 	setTexture(const std::string &);
    Position2D 	getPosition(void) const;
    void 	setPosition(Position2D&);
    void setColor(int, int, int, int);
    void 	setScale(float, float);
    void 	move(Position2D&);
    void 	move(float, float);

  bool isMouseOver(Window &);
    void onClick(std::function<void(Window &, sf::Event &)>, Window &, sf::Event &);
};


#endif /* !CPP_RTYPE_SPRITE_HPP_ */
