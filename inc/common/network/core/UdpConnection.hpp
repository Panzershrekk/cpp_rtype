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
# include "Endpoint.hpp"

class UdpConnection
{
private:
    UdpConnection(const Endpoint &, boost::asio::io_service &);
    UdpConnection(const std::string &ip, const unsigned short &port,
                      boost::asio::io_service &io_service);

    ~UdpConnection();

    const boost::asio::ip::udp::socket    &getSocket(void) const;

public:
    boost::asio::ip::udp::socket     _socket;
    std::string                     _outbound_header;
    std::string                     _outbound_data;
    char                            _inbound_header[8];
    std::string                     _inbound_data;
    Endpoint                        _endpoint;
};

#endif      /* !_UDP_CONNECTION__HPP_! */