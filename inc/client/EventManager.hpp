//
// Created by arthaox on 17/01/18.
//

#ifndef     _EVENTMANAGER__HPP_
# define    _EVENTMANAGER__HPP_
# include <vector>
# include "Player.hpp"
# include "Enemy.hpp"
# include "Room.hpp"
# include "common/network/core/UdpConnection.hpp"
# include "GameManager.hpp"

class EventManager
{
  public:
    EventManager();
    virtual ~EventManager();

    static void	sendFire(Network::Core::UdpConnection &, const Player &, const Network::Core::Endpoint &);
    static void	sendMove(Network::Core::UdpConnection &, const Player &, const Network::Core::Endpoint &);
};

#endif      /* !_EVENTMANAGER__HPP_! */
