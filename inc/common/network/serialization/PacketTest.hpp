/**
 * \file PacketTest.hpp
 * \brief TestPacket
 * \author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * \version 1.0
 * \date January 12, 2018
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 */

#ifndef     _PACKET_TEST__HPP_
# define    _PACKET_TEST__HPP_
#include "common/network/serialization/APacket.hpp"

namespace Network
{
    namespace Packet
    {
        class PacketTest : public Network::Packet::APacket
        {
            /* Attributes */
        public:
            int     data = 42;

            /* Methods */
        public:
            PacketTest() : APacket(Network::Packet::PacketType::PACKET_TEST) {};
            ~PacketTest() override = default;
        };
    }
}
#endif