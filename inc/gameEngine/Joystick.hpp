//
// Created by thomas on 12/01/18.
//

#ifndef CPP_RTYPE_JOYSTICK_HPP
#define CPP_RTYPE_JOYSTICK_HPP

#include <SFML/Window/Joystick.hpp>

class Joystick
{
  public:

    enum
    {
      Count       = 8,
      ButtonCount = 32,
      AxisCount   = 8
    };

    enum Axis
    {
      X,
      Y,
      Z,
      R,
      U,
      V,
      PovX,
      PovY
    };

    static bool isConnected(unsigned int joystick);
    static unsigned int getButtonCount(unsigned int joystick);
    static bool hasAxis(unsigned int joystick, Axis axis);
    static bool isButtonPressed(unsigned int joystick, unsigned int button);
    static float getAxisPosition(unsigned int joystick, Axis axis);
    static void update();
};

#endif //CPP_RTYPE_JOYSTICK_HPP
