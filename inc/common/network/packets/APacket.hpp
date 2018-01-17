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
            MAX = PACKET_PLAYER
        }               PacketType;

        class APacket
        {
        private:
            friend class boost::serialization::access;

            PacketType      _type;

        public:
            explicit APacket(const PacketType &type) : _type(type) {}

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