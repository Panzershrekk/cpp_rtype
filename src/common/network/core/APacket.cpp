/**
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 * Implementation of packet abstraction
 * @author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * @date January 12, 2018
 *
 */

#include "common/network/serialization/APacket.hpp"

Network::Packet::APacket::APacket() = default;

Network::Packet::APacket::APacket(const Network::Packet::PacketType &type) : _type(type) {}

Network::Packet::APacket::~APacket() {}

const Network::Packet::PacketType   &Network::Packet::APacket::getType() const
{
    return (this->_type);
}
