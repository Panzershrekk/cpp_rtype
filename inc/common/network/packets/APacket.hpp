#ifndef     _ABS_PACKET__HPP_
# define    _ABS_PACKET__HPP_

#include <boost/serialization/access.hpp>

namespace Network
{
    namespace Packet
    {
        typedef enum    PacketType
        {
            UNDEFINED = -1,
            MIN = UNDEFINED,
            PACKET_READY = 0,
            PACKET_ROOM = 1,
            PACKET_PLAYER = 2,
            PACKET_FIRE = 3,
            PACKET_MOVE = 4,
            PACKET_ENEMIES = 5,
            PACKET_PROJECTILES = 6,
            MAX = PACKET_PROJECTILES
        }               PacketType;

        class APacket
        {
        private:
            friend class boost::serialization::access;

            PacketType      _type;

        public:
            APacket() : _type(UNDEFINED) {}
            explicit APacket(const PacketType &type) : _type(type) {}
            APacket(const APacket& obj) { *this = obj; }

            PacketType		getType(void) const {return this->_type;}
            void			setType(const PacketType &type) {this->_type = type;}

            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
                ar & _type;
            }
        };
    }
}

#endif      /* !_ABS_PACKET__HPP_! */