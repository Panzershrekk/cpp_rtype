/**
 * \file main.c
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

class Serializer
{
public:
    Serializer() = default;
    virtual ~Serializer() = default;

    /**
     * Serializer
     * @tparam Obj : Represent a type to be serialize (type of obj)
     * @param obj : The object to be seralize
     * @param the serialize string
     */
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

    /**
     * DeSerializer
     * @tparam Obj : Represent the end type return
     * @param buf : The buffer need be deserialize
     * @return : The new object made by deserialization
     */
    static Network::Packet::APacket   *deserialize(const std::string &buf, const Network::Packet::PacketType &type)
    {
        return deserializePacketPlayer(buf);
    }

    static Network::Packet::APacket     *deserializePacketPlayer(const std::string &buf)
    {
        Network::Packet::APacket        *packet;
        Network::Packet::PacketPlayer   *packetPlayer = new Network::Packet::PacketPlayer;

        std::stringstream          archive_stream(buf);
        {
            boost::archive::binary_iarchive archive(archive_stream);
            archive >> *packetPlayer;
        }
        packet = packetPlayer;
        return (packet);
    }
};

#endif      /* !_SERIALIZER__HPP_! */
