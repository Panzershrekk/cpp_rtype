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
            PACKET_ROOM = 0,
            PACKET_PLAYER = 1,
            PACKET_FIRE = 2,
            PACKET_MOVE = 3,
            PACKET_ENEMIES = 4,
            MAX = PACKET_ENEMIES
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