/**
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 * Implementation of an udp connection (Boost::ASIO encapsulation)
 * @author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * @date January 10, 2018
 *
 */

#include "common/network/core/UdpConnection.hpp"

UdpConnection::UdpConnection(const std::string &ip, const unsigned short &port, boost::asio::io_service &io_service)
        : _endpoint(Endpoint(ip, port)),_socket(io_service) {}

UdpConnection::UdpConnection(const Endpoint &endpoint, boost::asio::io_service &io_service)
        : _endpoint(endpoint), _socket(io_service) {}

UdpConnection::~UdpConnection() = default;

const boost::asio::ip::udp::socket& UdpConnection::getSocket() const
{
    return this->_socket;
}