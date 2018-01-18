//
// Created by baudet_q on 18/01/18.
//

#ifndef STARFIELD_STAR_HPP
#define STARFIELD_STAR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>


class Star
{
  public:
    Star() {}
    Star(sf::Uint16, sf::Uint16);
    ~Star() {}
    sf::Uint16 getXPos();
    sf::Uint16 getYPos() const;
    void setXPos(sf::Uint16);
    void setYPos(sf::Uint16);
    void addXPos(sf::Uint16);
    void addYPos(sf::Uint16);

  private:
    sf::Uint16 xPos;
    sf::Uint16 yPos;
};

#endif //STARFIELD_STAR_HPP
