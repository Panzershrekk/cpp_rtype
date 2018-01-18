//
// Created by arthaox on 17/01/18.
//

#ifndef CPP_RTYPE_REQUESTMANAGER_HPP
#define CPP_RTYPE_REQUESTMANAGER_HPP

#include	"IPacket.hpp"

#include	<map>

template <typename T>
class RequestManager
{
  private:
    std::unordered_map<string, std::function<T>>	_manager;
  public:
    RequestManager();
    virtual ~RequestManager();

    void	CheckPacket(Packet &);
    void	handleRequest(Request, Object&);
    void	handleFireRequest(Object&);
    void	handleMoveRequest(Object&);
    void	handleConnection(Object&);
    void	handleJoin(Object&);
    void	handleReady(Object&);
};

#endif //CPP_RTYPE_REQUESTMANAGER_HPP
