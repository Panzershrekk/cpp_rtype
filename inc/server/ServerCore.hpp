/**
 * \file ServerCore.hpp
 * \brief Implementation of the ServerCore
 * \author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * \version 1.0
 * \date January 10, 2018
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 */

#ifndef     _SERVER_CORE__HPP_
# define    _SERVER_CORE__HPP_
# include <boost/asio.hpp>
# include <string>
# include "common/network/core/UdpConnection.hpp"

class ServerCore
{
    /* Attributes */
private:
    Network::Core::UdpConnection    _socket;
    std::stringstream               _ss;

    /* Functions */
private:
    bool    startExchanges();

public:
    ServerCore(boost::asio::io_service &service, const Network::Core::Endpoint &);
    ~ServerCore();

    bool    start(void);
};

#endif      /* !_SERVER_CORE__HPP_! */