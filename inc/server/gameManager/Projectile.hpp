//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_PROJECTILE_HPP
#define CPP_RTYPE_PROJECTILE_HPP

#include <AIManager.hpp>
#include "AEntity.hpp"

class Projectile : public AEntity
{
  public:
    explicit Projectile(const Position2D &);
    ~Projectile();

    void update();

  private:
   AIManager _ai;
};

#endif //CPP_RTYPE_PROJECTILE_HPP