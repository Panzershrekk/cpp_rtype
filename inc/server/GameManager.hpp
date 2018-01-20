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
    void addPlayer(Player& player);

    void updateEntities();
    void removeEntities();

    void dumpPlayer();
    void dumpEnnemy();

    bool playerStillAlive();

  private:
    Network::Core::UdpConnection &_socket;
    std::vector<Player> _player;
    std::vector<Enemy> _ennemy;
    std::vector<Projectile> _projetcile;

};

#endif //CPP_RTYPE_GAMEMANAGER_HPP
