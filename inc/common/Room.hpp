//
// Created by arthaox on 10/01/18.
//

#ifndef CPP_RTYPE_ROOM_HPP
#define CPP_RTYPE_ROOM_HPP

#include <iostream>
#include <vector>
#include "Player.hpp"

class Room
{
  private:
    int				        _size;
    int 			        _id;
    std::vector<Player>		_queue;

  public:
    Room();
    Room(const int &, const int &);
    ~Room();

    void			join(const Player &);
    void			leave(const Player &);
    int				getSize() const;
    int				getId() const;
    int 			setSize(const int &);
    int 			setId(const int &);
    std::vector<Player>		getPlayers() const;
    /*void 			sendData(data); preciser le type de data. Type socket ?*/

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
        ar & _size;
        ar & _id;
        ar & _queue;
    }

};

#endif //CPP_RTYPE_ROOM_HPP
