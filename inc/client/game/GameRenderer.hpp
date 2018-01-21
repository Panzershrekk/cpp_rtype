//
// Created by thomas on 17/01/18.
//

#ifndef CPP_RTYPE_GAMERENDERER_HPP
#define CPP_RTYPE_GAMERENDERER_HPP

#include <Window.hpp>
#include <SFML/Window/Event.hpp>
#include <TimeManager.hpp>
#include "PlayablePlayer.hpp"
#include "EnemyRenderer.hpp"
#include "gameManager/Enemy.hpp"

class GameRenderer
{
  public:
    explicit GameRenderer(Network::Core::UdpConnection &);
    ~GameRenderer();
    void startGame(Player &me, const Network::Core::Endpoint &);
    void updateEntities();
    void drawEntities(Window &);
    void destroyEntities();
    void addEnemies(Enemy &);

  private:
    PlayablePlayer                                  _player;
    std::vector<std::shared_ptr<EnemyRenderer>>     _enemies;
    TimeManager                                     _clock;
    TimeManager                                     _attackSpeed;
    Network::Core::UdpConnection                    &_socket;
};

#endif //CPP_RTYPE_GAMERENDERER_HPP
