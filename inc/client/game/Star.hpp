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
    Star(int, int);
    ~Star() {}

    int getXPos();
    int getYPos() const;
    void setXPos(int);
    void setYPos(int);
    void addXPos(int);
    void addYPos(int);

  private:
    int xPos;
    int yPos;
};

#endif //STARFIELD_STAR_HPP
