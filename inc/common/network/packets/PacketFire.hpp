//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_FIRE__HPP_
# define    _PACKET_FIRE__HPP_

# include <boost/serialization/base_object.hpp>
# include "APacket.hpp"
# include "common/Player.hpp"

namespace Network
{
    namespace Packet
    {
        class PacketFire : public APacket
        {
        private:
            friend class boost::serialization::access;
            Player      _player;

        public:
            PacketFire() : APacket(PACKET_FIRE) {}
            explicit PacketFire(const Player &player) : APacket(PACKET_PLAYER), _player(player) {}

            Player      &getPlayer() { return this->_player; }
            void         setPlayer(const Player &player) { this->_player = player; }

            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
                ar & boost::serialization::base_object<APacket>(*this);
                ar & _player;
            }
        };
    }
}

#endif      /* !_PACKET_FIRE__HPP_! */