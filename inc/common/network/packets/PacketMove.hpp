//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_MOVE__HPP_
# define    _PACKET_MOVE__HPP_

# include <boost/serialization/base_object.hpp>
# include "APacket.hpp"
# include "common/gameManager/Player.hpp"

namespace Network
{
    namespace Packet
    {
        class PacketMove : public APacket
        {
        private:
            friend class boost::serialization::access;
            Player      _player;

        public:
            PacketMove() : APacket(PACKET_MOVE) {}
            explicit PacketMove(const Player &player) : APacket(PACKET_MOVE), _player(player) {}

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