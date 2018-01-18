//
// Created by thomas on 17/01/18.
//

#ifndef CPP_RTYPE_ENEMY_HPP_
#define CPP_RTYPE_ENEMY_HPP_

#include <Sprite.hpp>
#include "AEntityRenderer.hpp"

class EnemyRenderer : public AEntityRenderer
{
  public:
    EnemyRenderer();
    ~EnemyRenderer();

    void update();

  private:
    void simulate();
};


#endif /* !CPP_RTYPE_ENEMY_HPP_ */
