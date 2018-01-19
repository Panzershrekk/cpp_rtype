//
// Created by baudet_q on 17/01/18.
//

#ifndef CPP_RTYPE_PARALAX_HPP
#define CPP_RTYPE_PARALAX_HPP

#include <Window.hpp>
#include <SFML/Window/Event.hpp>
#include <TimeManager.hpp>

class Paralax{
  public:
    Paralax();
    virtual ~Paralax();
    void update(Position2D); //TODO constness missing ?
    Position2D getPos() const;
    void setPos(Position2D);
    Sprite getBackground() const;
    void setBackground(Sprite);

  private:
    Position2D	_pos;
    Sprite	_background;
};
#endif //CPP_RTYPE_PARALAX_HPP
