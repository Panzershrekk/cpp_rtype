//
// Created by thomas on 16/01/18.
//

#include "AEntity.hpp"

AEntity::AEntity()
{
    static int id = 0;
    this->_id = id;
    id++;
}

AEntity::~AEntity()
{

}

AEntity::AEntity(const AEntity &obj)
{
    this->_id = obj._id;
    this->_rect = obj._rect;
    this->_physic = obj._physic;
    this->_hitboxSize = obj._hitboxSize;
}

void AEntity::setPosition(Position2D &pos)
{
    this->_pos = pos;
}

Position2D& AEntity::getPosition()
{
    return this->_pos;
}

int AEntity::getId() const
{
    return this->_id;
}