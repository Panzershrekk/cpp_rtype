//
// Created by thomas on 18/01/18.
//

#ifndef     _PROJECTILE_RENDER__HPP_
# define    _PROJECTILE_RENDER__HPP_

#include <Sprite.hpp>
#include "AEntityRenderer.hpp"

class ProjectileRenderer : public AEntityRenderer
{
public:
    explicit ProjectileRenderer(Position2D pos, const int &id);
    ~ProjectileRenderer() override;

    void update();

private:
    void simulate();
};

#endif      /* !_PROJECTILE_RENDER__HPP_! */