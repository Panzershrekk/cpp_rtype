//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_PLAYER__HPP_
# define    _PACKET_PLAYER__HPP_

#include <boost/serialization/base_object.hpp>
# include "APacket.hpp"
# include "common/Player.hpp"

namespace Network
{
    namespace Packet
    {
        class PacketPlayer : public APacket
        {
        private:
            friend class boost::serialization::access;
            Player      _player;

        public:
            explicit PacketPlayer(const Player &player) : APacket(PACKET_PLAYER), _player(player) {}

            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
                ar & boost::serialization::base_object<APacket>(*this);
                ar & _player;
            }
        };
    }
}

#endif      /* !_PACKET_PLAYER__HPP_! */