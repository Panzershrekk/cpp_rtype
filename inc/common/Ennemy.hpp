//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_ENNEMY_HPP
#define CPP_RTYPE_ENNEMY_HPP

#include <AIManager.hpp>
#include "Character.hpp"

class Ennemy : public Character
{
  public:
    Ennemy();
    ~Ennemy();

    void randomizePosition();
    AIManager getAI() const;

  private:
    AIManager _ai;
};

#endif //CPP_RTYPE_ENNEMY_HPP
