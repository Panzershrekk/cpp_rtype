//
// Created by thomas on 18/01/18.
//

#include <ProjectileRenderer.hpp>
#include <gameEngine/AIManager.hpp>

ProjectileRenderer::ProjectileRenderer(Position2D  pos, const int &id) : AEntityRenderer("../assets/boule.png")
{
    setPosition(pos + Position2D(20, 0));
    this->_sprite.setPosition(this->_pos);
    this->_id = id;
}

ProjectileRenderer::~ProjectileRenderer() = default;

void ProjectileRenderer::update()
{
    simulate();
}

void ProjectileRenderer::simulate()
{
    AIManager ai;

    ai.PredefinedLeftToRight(this->_pos, 10);
    this->_sprite.setPosition(this->_pos);
}
