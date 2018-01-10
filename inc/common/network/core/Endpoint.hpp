/**
 * \file UdpConnection.hpp
 * \brief Implementation of endpoint notion
 * \author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * \version 1.0
 * \date January 10, 2018
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 */

#ifndef     _ENDPOINT__HPP_
# define    _ENDPOINT__HPP_
# include <string>
# include <boost/asio.hpp>

class Endpoint
{
private:
    boost::asio::ip::address     _ip;
    unsigned short               _port;

public:
    Endpoint(const std::string &, const unsigned short &);
    ~Endpoint();
    void                    setIp(const std::string &);
    void                    setPort(const unsigned short &);
    const std::string       getIp() const;
    const unsigned short    &getPort() const;
};

#endif      /* !_ENDPOINT__HPP_! */
