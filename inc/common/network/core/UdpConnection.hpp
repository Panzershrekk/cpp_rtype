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
# include "common/network/core/Endpoint.hpp"
# include "Serializer.hpp"
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
            std::string                     _outboundData;
            std::string                     _outboundHeader;

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

            template <typename Handler>
            void    async_write(const Network::Packet::APacket &packet, const Endpoint &endpoint, Handler handler)
            {
                try
                {
                    this->_outboundData = Serializer::serialize(packet);

                    std::ostringstream      headerStream;
                    headerStream << std::setw(4) << std::hex << this->_outboundData.size();
                    headerStream << std::setw(4) << std::hex << packet.getType();

                    if (!headerStream || headerStream.str().size() != 8)
                        return;
                    this->_outboundHeader = headerStream.str();
                    std::vector<boost::asio::const_buffer>  buffers;
                    buffers.push_back(boost::asio::buffer(this->_outboundHeader));
                    buffers.push_back(boost::asio::buffer(this->_outboundData));
                    this->_socket.async_send_to(buffers, endpoint.getBoostEndpoint(), 0, handler);
                }
                catch (const std::exception &e)
                {
                    // IGNORED
                }
            }

            template <typename Handler, typename HandlerEndpoint>
            void        read(std::stringstream &ss, Handler handler, HandlerEndpoint handlerEp)
            {
                boost::system::error_code       errorCode;

                try
                {
                    boost::asio::ip::udp::endpoint          boostEndpointRemote;
                    std::array<char, 8>                     bufferHeader;

                    this->_socket.receive_from(boost::asio::buffer(bufferHeader),
                                               boostEndpointRemote, 0, errorCode);
                    if (errorCode)
                        handler(Error(INVALID_READ));
                    for (auto i = 0; i != 8; ++i) { this->_inboundHeader[i] = 0; }
                    for (int i = 0; i < 8; ++i) { this->_inboundHeader[i] = bufferHeader[i]; }
                    Endpoint remoteEndpoint(boostEndpointRemote.address().to_string(),
                                            boostEndpointRemote.port());
                    handlerEp(remoteEndpoint); // HANDLE NEW ENDPOINT
                }
                catch (const std::exception &e)
                {
                    handler(Error(INVALID_READ));
                }
                handleReadHeader(Error(NO_ERROR), ss, handler, handlerEp);
            }

            template<typename Handler, typename HandlerEndpoint>
            void    handleReadHeader(const Network::Core::Error &e,
                                     std::stringstream &ss,
                                     Handler handler,
                                     HandlerEndpoint handlerEp)
            {
                boost::system::error_code   errorCode;

                if (e.getCode() != NO_ERROR)
                    handler(e);
                else
                {
                    std::size_t         packetType = 0;

                    try
                    {
                        std::istringstream  isDatasize(std::string(this->_inboundHeader, 8));
                        if (!(isDatasize >> std::setw(8) >> std::hex >> this->_dataSize))
                        {
                            handler(Error(INVALID_HEADER_FORMAT));
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
                            handler(Error(INVALID_READ));
                            std::cerr << "DATA TOO LONG" << std::endl;
                            return;
                        }
                        for (auto i = 0; i != 1000; ++i)
                        {
                            bufferData[i] = 0;
                        }
                        this->_socket.receive_from(boost::asio::buffer(bufferData, this->_dataSize),
                                                   boostEndpointRemote, 0, errorCode);
                        std::cout << std::endl;
                        if (errorCode)
                        {
                            handler(Error(INVALID_READ));
                            return;
                        }
                        this->_inboundData = std::string(bufferData.begin(), bufferData.begin() + this->_dataSize);
                        Endpoint   remoteEndpoint(boostEndpointRemote.address().to_string(),
                                                  boostEndpointRemote.port());
                        handlerEp(remoteEndpoint);
                        handleReadData(Error(NO_ERROR), ss, handler ,handlerEp);
                    }
                    catch (const std::exception &e)
                    {
                        handler(Error(INVALID_HEADER_FORMAT));
                        return;
                    }
                }
            }

            template<typename Handler, typename HandlerEndpoint>
            void    handleReadData(const Network::Core::Error &e,
                                   std::stringstream &ss,
                                   Handler handler,
                                   HandlerEndpoint handlerEp)
            {
                if (e.getCode() != NO_ERROR)
                {
                    handler(e);
                    return;
                }
                ss = std::stringstream("");
                ss << this->_inboundData;
                handler(Error(NO_ERROR));
            }
        };
    }
}

#endif      /* !_UDP_CONNECTION__HPP_! */