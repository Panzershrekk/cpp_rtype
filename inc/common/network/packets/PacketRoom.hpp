//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_ROOM__HPP_
# define    _PACKET_ROOM__HPP_
# include <boost/serialization/base_object.hpp>
# include "APacket.hpp"
# include "common/gameManager/Room.hpp"

namespace Network
{
    namespace Packet
    {
        class PacketRoom : public APacket
        {
        private:
            friend class boost::serialization::access;
            Room        _room;

        public:
            PacketRoom() : APacket(PACKET_ROOM) {}
            explicit PacketRoom(const Room &room) : APacket(PACKET_ROOM), _room(room) {}

            Room        &getRoom() { return this->_room; }
            void        setRoom(const Room &room) { this->_room = room; }

            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
                ar & boost::serialization::base_object<APacket>(*this);
                ar & _room;
            }
        };
    }
}

#endif      /* !_PACKET_PLAYER__HPP_! */