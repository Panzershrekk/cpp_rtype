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
    Star(float, float);
    ~Star() {}

    float getXPos() const;
    float getYPos() const;
    void setXPos(float);
    void setYPos(float);
    void addXPos(float);
    void addYPos(float);

  private:
    float xPos;
    float yPos;
};

#endif //STARFIELD_STAR_HPP
