/**
 * \file Serializer.hpp
 * \brief Serialization Library
 * \author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * \version 1.0
 * \date January 10, 2018
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 */

#ifndef     _SERIALIZER__HPP_
# define    _SERIALIZER__HPP_
# include <ostream>
# include <boost/serialization/export.hpp>
# include <boost/archive/binary_iarchive.hpp>
# include <boost/archive/binary_oarchive.hpp>
# include <boost/serialization/vector.hpp>
# include <boost/serialization/access.hpp>
# include <boost/serialization/string.hpp>
# include <boost/serialization/shared_ptr.hpp>
# include <boost/serialization/serialization.hpp>
# include <iostream>
# include <sstream>
# include "common/network/packets/APacket.hpp"
# include "common/network/packets/PacketPlayer.hpp"
# include "common/network/packets/PacketRoom.hpp"

class Serializer
{

public:

public:
    Serializer() = default;

    virtual ~Serializer() = default;

    template <class Obj>
    static std::string    serialize(Obj &obj)
    {
        std::stringstream          archive_stream;
        {
            boost::archive::binary_oarchive archive(archive_stream);
            archive << obj;
        }
        std::string test = archive_stream.str();
        return archive_stream.str();
    }


    Network::Packet::APacket   *deserialize(const std::string &buf, const Network::Packet::PacketType &type)
    {
        std::map<Network::Packet::PacketType, std::function<Network::Packet::APacket *(const std::string &)>>    factory;

        factory.emplace(std::make_pair(Network::Packet::PacketType::PACKET_PLAYER, std::bind(
                &Serializer::deserializeSpecPacket<Network::Packet::PacketPlayer>,
                this,
                std::placeholders::_1)));
        factory.emplace(std::make_pair(Network::Packet::PacketType::PACKET_ROOM, std::bind(
                &Serializer::deserializeSpecPacket<Network::Packet::PacketRoom>,
                this,
                std::placeholders::_1)));

        for (auto packetFactory : factory)
        {
            if (packetFactory.first == type)
            {
                return packetFactory.second(buf);
            }
        }
        return nullptr;
    }

    template <typename T>
    Network::Packet::APacket     *deserializeSpecPacket(const std::string &buf)
    {
        Network::Packet::APacket        *packet;
        auto                            *packetSpec = new T;

        std::stringstream          archive_stream(buf);
        {
            boost::archive::binary_iarchive archive(archive_stream);
            archive >> *packetSpec;
        }
        packet = packetSpec;
        return (packet);
    }
};

#endif      /* !_SERIALIZER__HPP_! */
