/**
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 * Implementation of endpoint notion
 * @author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * @date January 10, 2018
 *
 */

#include "common/network/core/Endpoint.hpp"

Endpoint::Endpoint(const std::string &ip, const unsigned short &port)
        :_port(port)
{
    this->setIp(ip);
}

Endpoint::~Endpoint() = default;

void    Endpoint::setIp(const std::string &ip)
{
    this->_ip.from_string(ip);
}

void    Endpoint::setPort(const unsigned short &port)
{
    this->_port = port;
}

const std::string   Endpoint::getIp() const
{
    return "";
}
const unsigned short    &Endpoint::getPort() const
{
    return this->_port;
}