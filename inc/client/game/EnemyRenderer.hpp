//
// Created by thomas on 17/01/18.
//

#ifndef CPP_RTYPE_ENEMY_HPP_
#define CPP_RTYPE_ENEMY_HPP_


#include <Sprite.hpp>

class EnemyRenderer
{
  public:
    EnemyRenderer();
    ~EnemyRenderer();

    void update();
    Sprite &getSprite();
    Position2D getPosition() const;

  private:
    Sprite _sprite;
    Position2D _pos;

    void simulate();
};


#endif /* !CPP_RTYPE_ENEMY_HPP_ */
