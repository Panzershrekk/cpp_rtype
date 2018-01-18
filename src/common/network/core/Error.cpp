/**
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 * Implementation of Error for Network::Core
 * @author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * @date January 12, 2018
 *
 */

#include "common/network/core/Error.hpp"

Network::Core::Error::Error(const ErrorCode &code) : _code(code), _message(getMessageFromCode(code))
{

}

Network::Core::Error::~Error() = default;

const Network::Core::ErrorCode Network::Core::Error::getCode() const
{
    return this->_code;
}

const std::string Network::Core::Error::getMessage() const
{
    return this->_message;
}

const std::string    &Network::Core::Error::getMessageFromCode(
        const ErrorCode &code) const
{
    auto idx = this->_connections.find(code);
    if (idx == this->_connections.end())
    {
        throw Network::Core::Exception("Unknown error");
    }
    return this->_connections.at(code);
}