//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_GAMEMANAGER_HPP
#define CPP_RTYPE_GAMEMANAGER_HPP

#include <vector>
#include <iostream>
#include "AEntity.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"
#include "common/network/core/UdpConnection.hpp"

class GameManager
{
  public:
    GameManager(Network::Core::UdpConnection &);
    ~GameManager();

    void update();
    void spawnEnnemy();
    void createProjectile(Player &);
    void addPlayer(Player player);

    void updateEntities();
    void removeEntities();

    void dumpPlayer();
    void dumpEnemy();

    bool playerStillAlive();
    bool missileCollide();

    std::vector<Player>   &getPlayers();
    const std::vector<Enemy>    &getEnemies() const;
    const std::vector<Projectile>    &getProjectiles() const;

  private:
    Network::Core::UdpConnection    &_socket;
    std::vector<Player>             _player;
    std::vector<Enemy>              _ennemy;
    std::vector<Projectile>         _projectile;

};

#endif //CPP_RTYPE_GAMEMANAGER_HPP
