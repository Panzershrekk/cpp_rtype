//
// Created by arthaox on 10/01/18.
//

#include		"../../../inc/server/Room.hpp"

Room::Room()
{

}

Room::Room(const int size, const int id) : _size(size), _id(id) {}

Room::~Room()
{

}

void			Room::join(Player player)
{
 this->_queue.insert(player);
}

void			Room::leave(Player player)
{
 for (std::vector<Player>::iterator it = _queue.begin(); it != _queue.end(); it++)
 {
   if (it.getId() == player.getId())
     _queue.erase(it);
 }
}

int			Room::setSize(const int size)
{
  this->_size = size;
}

int			Room::setId(const int id)
{
  this->_id = id;
}

int			Room::getSize() const
{
  return(this->_size);
}

int			Room::getId() const
{
  return(this->_id);
}

std::vector<Player>	Room::getPlayer() const
{
  return (this->_queue);
}