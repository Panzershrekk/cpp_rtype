/**
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 * Implementation of endpoint notion
 * @author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * @date January 10, 2018
 *
 */

#include <boost/asio.hpp>
#include <iostream>
#include "common/network/core/Endpoint.hpp"

Network::Core::Endpoint::Endpoint(const std::string &ip, const unsigned short &port)
        : _port(port), _endpoint(boost::asio::ip::address::from_string(ip), port)
{
    this->setIp(ip);
}

Network::Core::Endpoint::Endpoint(const unsigned short &port)
        : _port(port), _endpoint(boost::asio::ip::address::from_string("0.0.0.0"), port)
{
    this->setIp("0.0.0.0");
}

Network::Core::Endpoint::Endpoint(const Network::Core::Endpoint &obj)
{
    this->_ip = obj._ip;
    this->_port = obj._port;
    this->_endpoint = obj._endpoint;
}

Network::Core::Endpoint::~Endpoint() = default;

Network::Core::Endpoint    &Network::Core::Endpoint::operator=(const Network::Core::Endpoint &obj)
{
    this->_ip = obj._ip;
    this->_port = obj._port;
    this->_endpoint = obj._endpoint;
    return (*this);
}

void    Network::Core::Endpoint::setIp(const std::string &ip)
{
    this->_ip.from_string(ip);
    this->_endpoint.address(boost::asio::ip::address::from_string(ip));
}

void    Network::Core::Endpoint::setPort(const unsigned short &port)
{
    this->_port = port;
    this->_endpoint.port(port);
}

const boost::asio::ip::address  &Network::Core::Endpoint::getIp() const
{
    return this->_ip;
}

const unsigned short    &Network::Core::Endpoint::getPort() const
{
    return this->_port;
}

const boost::asio::ip::udp::endpoint    &Network::Core::Endpoint::getBoostEndpoint() const
{
    return this->_endpoint;
}