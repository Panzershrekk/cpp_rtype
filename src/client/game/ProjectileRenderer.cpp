//
// Created by thomas on 18/01/18.
//

#include <ProjectileRenderer.hpp>

ProjectileRenderer::ProjectileRenderer(Position2D  pos) : AEntityRenderer("../assets/Missile.png")
{
    setPosition(pos + Position2D(20, 0));
    this->_sprite.setPosition(this->_pos);
}

ProjectileRenderer::~ProjectileRenderer() {

}

void ProjectileRenderer::update()
{
    simulate();
}

void ProjectileRenderer::simulate()
{
    this->_pos += Position2D(1, 0);
    this->_sprite.setPosition(this->_pos);
}
