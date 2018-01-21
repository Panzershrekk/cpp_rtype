//
// Created by guillobits on 20/01/18.
//

#ifndef     _CLIENT_CORE__HPP_
# define    _CLIENT_CORE__HPP_

#include <thread>
#include "client/menu/MenuWindow.hpp"
#include "client/game/GameRenderer.hpp"
#include "client/RequestManager.hpp"
#include "common/network/core/UdpConnection.hpp"

class ClientCore
{
private:
    Network::Core::UdpConnection    _socket;
    // MenuWindow                   _menu;
    GameRenderer                    _gameRender;
    RequestManager                  _requestManager;
    Network::Core::Endpoint         _endpointServer; //TODO
    Player                          _player;

public:
    explicit ClientCore(boost::asio::io_service &service);
    ~ClientCore();
    void            start();
    void            startExchanges();
    std::thread     runService();
};

#endif      /* !_CLIENT_CORE__HPP_! */
