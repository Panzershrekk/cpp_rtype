//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_READY__HPP_
# define    _PACKET_READY__HPP_

# include <boost/serialization/base_object.hpp>
# include "APacket.hpp"

// TODO: Envoie de ce paquet en boucle par le client graphique et attente d'une réponse d'une serveur.

namespace Network
{
    namespace Packet
    {
        class PacketReady : public APacket
        {
        private:
            friend class boost::serialization::access;
            int      _player;

        public:
            PacketReady() : APacket(PACKET_FIRE) {}
            explicit PacketReady(const int &player) : APacket(PACKET_PLAYER), _player(player) {}

            const int    &getPlayer() { return this->_player; }
            void         setPlayer(const int &player) { this->_player = player; }

            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
                ar & boost::serialization::base_object<APacket>(*this);
                ar & _player;
            }
        };
    }
}

#endif      /* !_PACKET_READY__HPP_! */