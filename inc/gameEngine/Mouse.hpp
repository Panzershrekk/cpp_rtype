//
// Created by thomas on 12/01/18.
//

#ifndef CPP_RTYPE_MOUSE_HPP
#define CPP_RTYPE_MOUSE_HPP

#include <SFML/Window/Mouse.hpp>
#include "Position2D.hpp"
#include "Window.hpp"

class Mouse
{
  public:
    enum Button
    {
      Left,
      Right,
      Middle,
      XButton1,
      XButton2,
      ButtonCount
    };

    static bool isButtonPressed(Button button);
    static Position2D getPosition();
    static Position2D getPosition(Window& relativeTo);

    static void setPosition(const Position2D& position);
    //static void setPosition(const Vector2i& position, const Window& relativeTo); //TODO See with Robin
};

#endif //CPP_RTYPE_MOUSE_HPP
