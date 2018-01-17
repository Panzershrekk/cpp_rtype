/**
 * \file UdpConnection.hpp
 * \brief Implementation of an udp connection (Boost::ASIO encapsulation)
 * \author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * \version 1.0
 * \date January 10, 2018
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 */

#ifndef     _A_PACKET__HPP_
# define    _A_PACKET__HPP_
#include <string>
#include <memory>

namespace Network
{
    namespace Packet
    {
        typedef enum    PacketType
        {
            UNDEFINED,
            PLAYER_MOVE,
            PLAYER_FIRE,
            PLAYER,
            ENEMY,
            ENEMIES,
            ROOM,
            ROOMS,
            GAME,
            JOIN_ROOM,
            LEAVE_ROOM,
            COLLIDE_ENEMY,
            LIVE,

        }               PacketType;

        class APacket
        {
        private:
            const PacketType     _type = UNDEFINED;

        public:
            APacket();
            APacket(const PacketType &type);
            virtual ~APacket();


            const PacketType &getType() const;
        };
    }
}

#endif      /* !_A_PACKET__HPP_! */