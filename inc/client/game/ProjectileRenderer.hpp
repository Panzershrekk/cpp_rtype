//
// Created by thomas on 18/01/18.
//

#ifndef CPP_RTYPE_PROJECTILE_HPP
#define CPP_RTYPE_PROJECTILE_HPP

#include <Sprite.hpp>
#include "AEntityRenderer.hpp"

class ProjectileRenderer : public AEntityRenderer
{
public:
    ProjectileRenderer(Position2D pos);
    ~ProjectileRenderer();

    void update();

private:
    void simulate();
};

#endif //CPP_RTYPE_PROJECTILE_HPP
