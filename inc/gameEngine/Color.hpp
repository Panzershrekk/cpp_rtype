//
// Created by grodin on 10/01/18.
//

#ifndef CPP_RTYPE_COLOR_HPP_
#define CPP_RTYPE_COLOR_HPP_

#include	<SFML/Graphics/Color.hpp>

class Color
{
  private:
    sf::Color	_color;

  public:
    Color();
    Color(int, int, int);
    Color(int, int, int, int);
    int getRed(void) const;
    int getGreen(void) const;
    int getBlue(void) const;
    int getAlpha(void) const;
    ~Color();
};


#endif /* !CPP_RTYPE_COLOR_HPP_ */
