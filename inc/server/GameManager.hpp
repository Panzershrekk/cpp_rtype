//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_GAMEMANAGER_HPP
#define CPP_RTYPE_GAMEMANAGER_HPP

#include <vector>
#include <iostream>
#include "server/GameManager/AEntity.hpp"
#include "server/GameManager/Player.hpp"
#include "server/GameManager/Projectile.hpp"
#include "server/GameManager/Enemy.hpp"

class GameManager
{
  public:
    GameManager();
    ~GameManager();

    void update();
    void spawnEnnemy();
    void createProjectile();
    void addPlayer(Player& player);

    void dumpPlayer();
    void dumpEnnemy();

  private:
    std::vector<Player> _player;
    std::vector<Enemy> _ennemy;
    std::vector<Projectile> _projetcile;

};

#endif //CPP_RTYPE_GAMEMANAGER_HPP
