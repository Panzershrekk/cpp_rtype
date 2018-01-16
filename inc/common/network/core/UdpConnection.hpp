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

#ifndef     _UDP_CONNECTION__HPP_
# define    _UDP_CONNECTION__HPP_
# include <boost/asio.hpp>
# include <string>
# include <iomanip>
# include <sstream>
# include <iostream>
# include <tuple>
# include "common/network/core/Endpoint.hpp"
# include "common/network/serialization/Serializer.hpp"
# include "common/network/serialization/APacket.hpp"
# include "common/network/serialization/PacketTest.hpp"
# include "common/network/core/Error.hpp"

namespace Network
{
    namespace Core
    {
        class UdpConnection
        {
        private:
            boost::asio::ip::udp::socket    _socket;
            char                            _inboundHeader[8];
            std::string                     _inboundData;
            std::size_t                     _dataSize = 0;
            Network::Packet::PacketType     _packetType = Network::Packet::PacketType::UNDEFINED;

        public:
            UdpConnection(boost::asio::io_service &ioService, const Endpoint &ep) :
                    _socket(ioService, ep.getBoostEndpoint()) {}
            UdpConnection(boost::asio::io_service &ioService)
                    : _socket(ioService) {}
            UdpConnection(const std::string &ip, const unsigned short &port,
                          boost::asio::io_service &io_service)
                    : _socket(io_service, Endpoint(ip, port).getBoostEndpoint()){};
            ~UdpConnection() = default;

            void    openV4()
            {
                this->_socket.open(boost::asio::ip::udp::v4());
            }

            void    send(Network::Packet::APacket &packet, const Endpoint &endpoint)
            {
                try
                {
                    std::string         outboundData = Serializer::serialize(packet);
                    std::stringstream   headerStream;

                    headerStream << std::setw(4) << std::hex << outboundData.size() << std::setw(4) << packet.getType();

                    if (!headerStream || headerStream.str().size() != 8)
                    {
                        return;
                    }
                    auto outbound_header = headerStream.str();
                    std::vector<boost::asio::const_buffer>  buffer;
                    buffer.push_back(boost::asio::buffer(outbound_header));
                    buffer.push_back(boost::asio::buffer(outboundData));
                    this->_socket.send_to(buffer, endpoint.getBoostEndpoint());
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << std::endl;
                }
            }

            template <typename Handler>
            void        read(Network::Packet::APacket &packet, Handler handler)
            {
                boost::system::error_code       errorCode;

                try
                {
                    boost::asio::ip::udp::endpoint  boostEndpointRemote;
                    std::array<char, 8>             bufferHeader;

                    for (int i = 0; i < 8; ++i)
                        bufferHeader[i] = ' ';
                    this->_socket.receive_from(boost::asio::buffer(bufferHeader),
                                               boostEndpointRemote, 0, errorCode);
                    if (errorCode)
                        handler(Error(INVALID_READ), packet);
                    for (int i = 0; i < 8; ++i)
                        this->_inboundHeader[i] = bufferHeader[i];
                    Endpoint remoteEndpoint(boostEndpointRemote.address().to_string(),
                                            boostEndpointRemote.port());
                    // TODO: HANDLER REMOTE ENDPOINT
                }
                catch (const std::exception &e)
                {
                    handler(Error(INVALID_READ), packet);
                }
                handleReadHeader(Error(NO_ERROR), packet, handler);
            }

            template<typename Handler>
            void    handleReadHeader(const Network::Core::Error &e,
                                     Network::Packet::APacket &packet,
                                     Handler handler)
            {
                boost::system::error_code   errorCode;

                if (e.getCode() != NO_ERROR)
                    handler(e, packet);
                else
                {
                    std::size_t         packetType = 0;

                    try
                    {
                        /**
                         * HANDLE HEADER
                         */
                        std::istringstream  isDatasize(std::string(this->_inboundHeader, 4));
                        std::istringstream  isPacketType(std::string(this->_inboundHeader + 4, 4));

                        if (!(isDatasize >> std::setw(4) >> std::hex >> this->_dataSize) ||
                            !(isPacketType >> std::setw(4) >> std::hex >> packetType))
                        {
                            handler(Error(INVALID_HEADER_FORMAT), packet);
                            return;
                        }
                        this->_packetType = (Network::Packet::PacketType)packetType;
                        if (this->_packetType < Network::Packet::MIN ||
                            this->_packetType > Network::Packet::MAX)
                        {
                            handler(Error(INVALID_HEADER_FORMAT), packet);
                            return;
                        }
                        this->_inboundData.clear();
                        this->_inboundData.resize(this->_dataSize);

                        /**
                         * READ DATA
                         */
                        boost::asio::ip::udp::endpoint              boostEndpointRemote;
                        std::array<char, 1000>                      bufferData;
                        if (this->_dataSize > 1000)
                        {
                            handler(Error(INVALID_READ), packet);
                            std::cerr << "DATA TOO LONG" << std::endl;
                            return;
                        }
                        this->_socket.receive_from(boost::asio::buffer(bufferData, this->_dataSize),
                                                   boostEndpointRemote, 0, errorCode);
                        if (errorCode)
                        {
                            handler(Error(INVALID_READ), packet);
                            return;
                        }
                        this->_inboundData = std::string(bufferData.begin(), bufferData.end());
                        Endpoint   remoteEndpoint(boostEndpointRemote.address().to_string(),
                                                  boostEndpointRemote.port());
                        // TODO: HANDLER REMOTE ENDPOINT
                        handleReadData(Error(NO_ERROR), packet, handler);
                    }
                    catch (const std::exception &e)
                    {
                        handler(Error(INVALID_HEADER_FORMAT), packet);
                        return;
                    }
                }
            }

            template<typename Handler>
            void    handleReadData(const Network::Core::Error &e, Network::Packet::APacket &packet, Handler handler)
            {
                /**
                 * HANDLE DATA
                 */
                if (e.getCode() != NO_ERROR)
                {
                    handler(e, packet);
                    return;
                }
                else
                {
                    try
                    {
                        std::cout << packet.getType() << std::endl;
                        Serializer::deserialize(this->_inboundData, packet);
                        std::cout << packet.getType() << std::endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << std::endl;
                        handler(Error(INVALID_DATA_CONTENT), packet);
                    }
                    handler(Error(NO_ERROR), packet);
                }
            }
        };
    }
}

#endif      /* !_UDP_CONNECTION__HPP_! */