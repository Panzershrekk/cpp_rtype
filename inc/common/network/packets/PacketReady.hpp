//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_READY__HPP_
# define    _PACKET_READY__HPP_

# include <boost/serialization/base_object.hpp>
# include "APacket.hpp"
# include "common/Player.hpp"

// TODO: Envoie de ce paquet en boucle par le client graphique et attente d'une réponse d'une serveur.

namespace Network
{
    namespace Packet
    {
        class PacketReady : public APacket
        {
        private:
            friend class boost::serialization::access;
            Endpoint    _endpoint;
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