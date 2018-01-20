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
# include "common/network/packets/APacket.hpp"
# define MAX_READ (1500)

namespace Network
{
    namespace Core
    {
        class UdpConnection
        {
        private:
            boost::asio::ip::udp::socket    _socket;
            std::string                     _inboundData;

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
            void    async_write(const std::string &data, const Network::Packet::PacketType &packetType, const Endpoint &endpoint, Handler handler)
            {
                try
                {
                    std::ostringstream       stream;

                    stream << std::setw(8) << std::hex << packetType << data;
                    this->_socket.async_send_to(boost::asio::buffer(stream.str()),
                                                endpoint.getBoostEndpoint(),
                                                0,
                                                handler);
                }
                catch (const std::exception &e)
                {
                    // IGNORED
                }
            }

            template <typename Handler>
            void        read(std::array<char, MAX_READ> &data, boost::asio::ip::udp::endpoint &ep, Handler handler)
            {
                try
                {
                    this->_socket.async_receive_from(boost::asio::buffer(data),
                                                     ep,
                                                     handler
                    );
                }
                catch (const std::exception &e)
                {
                    // IGNORED
                }
            }

        };
    }
}

#endif      /* !_UDP_CONNECTION__HPP_! */